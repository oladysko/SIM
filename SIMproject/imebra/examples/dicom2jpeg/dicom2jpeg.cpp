/*

Imebra 2011 build 2013-09-04_11-02-26

Imebra: a C++ Dicom library

Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013 by Paolo Brandoli/Binarno s.p.
All rights reserved.

This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License version 2 as published by
 the Free Software Foundation.

This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

-------------------

If you want to use Imebra commercially then you have to buy the commercial
 support available at http://imebra.com

After you buy the commercial support then you can use Imebra according
 to the terms described in the Imebra Commercial License Version 1.
A copy of the Imebra Commercial License Version 1 is available in the
 documentation pages.

Imebra is available at http://imebra.com

The author can be contacted by email at info@binarno.com or by mail at
 the following address:
 Paolo Brandoli
 Rakuseva 14
 1000 Ljubljana
 Slovenia



*/

#include <iostream>


#include "../../library/imebra/include/imebra.h"
#include <sstream>

#ifdef PUNTOEXE_WINDOWS
#include <process.h>
#else
#include <spawn.h>
#include <sys/wait.h>
#endif

#include <memory>
#include <list>

using namespace puntoexe;
using namespace puntoexe::imebra;

int findArgument(const char* argument, int argc, char* argv[])
{
	for(int scanArg(0); scanArg != argc; ++scanArg)
	{
		if(std::string(argv[scanArg]) == argument)
		{
			return scanArg;
		}
	}
	return -1;
}



int main(int argc, char* argv[])
{
	std::wstring version(L"1.0.0.1");
        std::wcout << L"dicom2jpeg version " << version << std::endl;

	try
	{

		if(argc < 3)
		{
                    std::wcout << L"Usage: dicom2jpeg dicomFileName jpegFileName [-ffmpeg FFMPEGPATH FFMPEGOPT]" << std::endl;
                    std::wcout << "dicomFileName        = name of the dicom file" << std::endl;
                    std::wcout << "jpegFileName         = name of the final jpeg file" << std::endl;
                    std::wcout << "-ffmpeg FFMPEGPATH   = launches FFMPEG after generating the jpeg images." << std::endl;
                    std::wcout << " FFMPEGPATH is the path to FFMPEG" << std::endl;
                    std::wcout << " FFMPEGOPT are the options for ffmpeg" << std::endl;
                    std::wcout << " The input images and the frame rate are added automatically to the options" << std::endl;
                    return 1;
		}

		// Separate the extension from the file name
		std::string outputFileName(argv[2]);
		std::string extension;
		size_t dotPos(outputFileName.rfind('.'));
		if(dotPos != outputFileName.npos)
		{
			extension = outputFileName.substr(dotPos);
			outputFileName.erase(dotPos);
		}
		else
		{
			extension = ".jpg";
		}

                // Check for the -ffmpeg flag
                int ffmpegFlag(findArgument("-ffmpeg", argc, argv));
                size_t framesCount(0);
                ptr<dataSet> loadedDataSet;

                try
                {

                    // Open the file containing the dicom dataset
                    ptr<puntoexe::stream> inputStream(new puntoexe::stream);
                    inputStream->openFile(argv[1], std::ios_base::in);

                    // Connect a stream reader to the dicom stream. Several stream reader
                    //  can share the same stream
                    ptr<puntoexe::streamReader> reader(new streamReader(inputStream));

                    // Get a codec factory and let it use the right codec to create a dataset
                    //  from the input stream
                    ptr<codecs::codecFactory> codecsFactory(codecs::codecFactory::getCodecFactory());
                    loadedDataSet = codecsFactory->load(reader, 2048);


                    // Get the first image. We use it in case there isn't any presentation VOI/LUT
                    //  and we have to calculate the optimal one
                    ptr<image> dataSetImage(loadedDataSet->getImage(0));
                    imbxUint32 width, height;
                    dataSetImage->getSize(&width, &height);


                    // Build the transforms chain
                    ptr<transforms::transformsChain> chain(new transforms::transformsChain);

                    ptr<transforms::modalityVOILUT> modalityVOILUT(new transforms::modalityVOILUT(loadedDataSet));
                    chain->addTransform(modalityVOILUT);

                    ptr<transforms::colorTransforms::colorTransformsFactory> colorFactory(transforms::colorTransforms::colorTransformsFactory::getColorTransformsFactory());
                    if(colorFactory->isMonochrome(dataSetImage->getColorSpace()))
                    {
                        // Convert to MONOCHROME2 if a modality transform is not present
                        ////////////////////////////////////////////////////////////////
                        if(modalityVOILUT->isEmpty())
                        {
                            ptr<transforms::colorTransforms::colorTransform> monochromeColorTransform(colorFactory->getTransform(dataSetImage->getColorSpace(), L"MONOCHROME2"));
                            if(monochromeColorTransform != 0)
                            {
                                chain->addTransform(monochromeColorTransform);
                            }
                        }

                        ptr<transforms::VOILUT> presentationVOILUT(new transforms::VOILUT(loadedDataSet));
                        imbxUint32 firstVOILUTID(presentationVOILUT->getVOILUTId(0));
                        if(firstVOILUTID != 0)
                        {
                            presentationVOILUT->setVOILUT(firstVOILUTID);
                        }
                        else
                        {
                            // Run the transform on the first image
                            ///////////////////////////////////////
                            ptr<image> temporaryImage = chain->allocateOutputImage(dataSetImage, width, height);
                            chain->runTransform(dataSetImage, 0, 0, width, height, temporaryImage, 0, 0);

                            // Now find the optimal VOILUT
                            //////////////////////////////
                            presentationVOILUT->applyOptimalVOI(temporaryImage, 0, 0, width, height);
                        }
                        chain->addTransform(presentationVOILUT);
                    }

                    std::wstring initialColorSpace;
                    if(chain->isEmpty())
                    {
                        initialColorSpace = dataSetImage->getColorSpace();
                    }
                    else
                    {
                        ptr<image> startImage(chain->allocateOutputImage(dataSetImage, 1, 1));
                        initialColorSpace = startImage->getColorSpace();
                    }

                    // Color transform to YCrCb
                    ptr<transforms::colorTransforms::colorTransform> colorTransform(colorFactory->getTransform(initialColorSpace, L"YBR_FULL"));
                    if(colorTransform != 0)
                    {
                        chain->addTransform((colorTransform));
                    }

                    ptr<image> finalImage(new image);
                    finalImage->create(width, height, image::depthU8, L"YBR_FULL", 7);

                    // Scan through the frames
                    for(imbxUint32 frameNumber(0); ; ++frameNumber)
                    {
                        if(frameNumber != 0)
                        {
                            dataSetImage = loadedDataSet->getImage(frameNumber);
                        }


                        if(chain->isEmpty() && dataSetImage->getDepth() != finalImage->getDepth() && dataSetImage->getHighBit() != finalImage->getHighBit())
                        {
                            chain->addTransform(new transforms::transformHighBit);
                        }

                        if(!chain->isEmpty())
                        {
                            chain->runTransform(dataSetImage, 0, 0, width, height, finalImage, 0, 0);
                        }
                        else
                        {
                            finalImage = dataSetImage;
                        }

                        // Open a stream for the jpeg
                        const std::wstring jpegTransferSyntax(L"1.2.840.10008.1.2.4.50");
                        std::ostringstream jpegFileName;
                        jpegFileName << outputFileName;
                        if(frameNumber != 0 || ffmpegFlag >= 0)
                        {
                                jpegFileName << "_" << frameNumber;
                        }
                        jpegFileName << extension;
                        ptr<puntoexe::stream> jpegStream(new puntoexe::stream);
                        jpegStream->openFile(jpegFileName.str(), std::ios_base::out | std::ios_base::trunc);
                        ptr<puntoexe::streamWriter> jpegWriter(new streamWriter(jpegStream));
                        ptr<codecs::codec> outputCodec(codecsFactory->getCodec(jpegTransferSyntax));

                        // Write the jpeg image to the stream
                        outputCodec->setImage(jpegWriter, finalImage, jpegTransferSyntax, codecs::codec::veryHigh,
                                "OB", 8, false, false, false, false);

                        ++framesCount;
                    }

		}
		catch(dataSetImageDoesntExist&)
		{
			// Ignore this exception. It is thrown when we reach the
			//  end of the images list
			exceptionsManager::getMessage();
		}

		// All the images have been generated.
		// Should we launch FFMPEG?
		if(ffmpegFlag >= 0 && framesCount != 0)
		{
			// List of arguments to be passed to ffmpeg
			typedef std::list<std::string> tOptionsList;
			tOptionsList options;

			// The first argument is the application's name
			options.push_back(argv[ffmpegFlag + 1]);

			// Calculate the frames per second from the available tags
			double framesPerSecond(0);
			double frameTime(loadedDataSet->getDouble(0x0018, 0, 0x1063, 0));
			if(frameTime > 0.1)
			{
				framesPerSecond = 1000 / frameTime;
			}
			if(framesPerSecond < 0.1)
			{
				framesPerSecond = loadedDataSet->getUnsignedLong(0x0018, 0x0, 0x0040, 0x0);
			}
			if(framesPerSecond < 0.1)
			{
				framesPerSecond = loadedDataSet->getUnsignedLong(0x0008, 0x0, 0x2144, 0x0);
			}

			// Add the ffmpeg argument for the frames per second
			if(framesPerSecond > 0.1)
			{
				options.push_back("-r");
				std::ostringstream frameRate;
				frameRate << framesPerSecond;
				options.push_back(frameRate.str());
			}

			// Add the ffmpeg argument for the input files
			options.push_back("-i");
			options.push_back(outputFileName + "_%d" + extension);

			// Add the ffmpeg argument for the number of frames
			options.push_back("-dframes");
			std::ostringstream frameCount;
			frameCount << (unsigned long)framesCount;
			options.push_back(frameCount.str());

			// Add the arguments specified when dicom2jpeg was launched
			for(int copyArguments(ffmpegFlag + 2); copyArguments < argc; ++copyArguments)
			{
				options.push_back(argv[copyArguments]);
			}

			// Build the arguments array
			std::auto_ptr<const char*> ffArgv(new const char*[options.size() + 1]);
			size_t insertPosition(0);
			for(tOptionsList::iterator scanOptions(options.begin()); scanOptions != options.end(); ++scanOptions, ++insertPosition)
			{
				ffArgv.get()[insertPosition] = (*scanOptions).c_str();
			}
			ffArgv.get()[options.size()] = 0;

			// Launch ffmpeg
#ifdef PUNTOEXE_WINDOWS
            return (int)_spawnvp(_P_WAIT , argv[ffmpegFlag + 1], ffArgv.get());
#else
            char *environment[] = {0};

            pid_t process_id;
            posix_spawnp (&process_id, argv[ffmpegFlag + 1],
                            0, 0, (char* const*)ffArgv.get(), (char* const*)environment);
            wait(0);
#endif

		}

		return 0;

	}
	catch(...)
	{
		std::wcout << exceptionsManager::getMessage();
		return 1;
	}
}

