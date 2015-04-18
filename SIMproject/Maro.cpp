#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include "Maro.h"

#include "C:/Users/CLEVO/Desktop/imebra/library/imebra/include/imebra.h"
#include "C:/Users/CLEVO/Desktop/imebra/library/base/include/configuration.h"

using namespace std;
using namespace puntoexe;

namespace puntoexe
{
	namespace imebra
	{
		namespace Maro
		{
			void getFrameSize(imbxUint32 frameNumber, std::string fileName, imbxUint32& height, imbxUint32& width)
			{
				std::cout << "getFrameSize" << std::endl;
				ptr<stream> readStream(new stream);
				readStream->openFile(fileName, std::ios::in);

				//parse content of the file
				ptr<streamReader> reader(new streamReader(readStream));
				ptr<dataSet> testDataSet = codecs::codecFactory::getCodecFactory()->load(reader);

				//read image
				ptr<image> Image = testDataSet->getImage(frameNumber);
				Image->getSize(&width, &height);
			}

			void getValuesMatrix(imbxUint32 frameNumber, std::string fileName, imbxUint32 height, imbxUint32 width, int * outputMatrix)
			{
				ptr<stream> readStream(new stream);
				readStream->openFile(fileName, std::ios::in);

				ptr<streamReader> reader(new streamReader(readStream));
				ptr<dataSet> testDataSet = codecs::codecFactory::getCodecFactory()->load(reader);

				//read image
				ptr<image> firstImage = testDataSet->getImage(frameNumber);
				ptr<transforms::transform> modVOILUT(new transforms::modalityVOILUT(testDataSet));
				ptr<image> convertedImage(modVOILUT->allocateOutputImage(firstImage, width, height));
				ptr<transforms::VOILUT> myVoiLut(new transforms::VOILUT(testDataSet));

				//Apply the first VOI or LUT
				imbxUint32 lutId = myVoiLut->getVOILUTId(0);
				myVoiLut->setVOILUT(lutId);

				//prepare image for presentation
				ptr<image> presentationImage(myVoiLut->allocateOutputImage(convertedImage, width, height));
				myVoiLut->runTransform(convertedImage, 0, 0, width, height, presentationImage, 0, 0);

				//============================================================================================================
				imbxUint32 rowSize, channelPixelSize, channelNumber;
				ptr<imebra::handlers::dataHandlerNumericBase> myHandler = presentationImage->getDataHandler(false, &rowSize, &channelNumber, &channelNumber);

				//Retrive image's size in pizels
				imbxUint32 sizeX, sizeY;
				presentationImage->getSize(&sizeX, &sizeY);
				//scan all the rows
				imbxUint32 index(0);
				for (imbxUint32 scanY = 0; scanY < height; ++scanY){
					//scan all the colums
					for (imbxUint32 scanX = 0; scanX < width; ++scanX){
						for (imbxUint32 scanChannel = 0; scanChannel < channelNumber; ++scanChannel){
							imbxInt32 channelValue = myHandler->getSignedLong(index++);
							outputMatrix[scanX + scanY*height] = (int)channelValue;
						}
					}
				}
			}
		}
	}
}