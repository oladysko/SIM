#include "DicomDataAdapter.h"
#include <iostream>
#include "./imebra/library/imebra/include/imebra.h"
#include "./imebra/library/base/include/configuration.h"

DicomDataAdapter::DicomDataAdapter(std::string fileName)
{

	ptr<puntoexe::stream> inputStream(new puntoexe::stream);
	inputStream->openFile(fileName, std::ios_base::in);
	ptr<streamReader> reader(new streamReader(inputStream));
	ptr<codecs::codecFactory> codecsFactory(codecs::codecFactory::getCodecFactory());

	DicomDataAdapter::dataSet = codecsFactory->load(reader);
	DicomDataAdapter::currentFrameNumber = 0;
}


DicomDataAdapter::~DicomDataAdapter()
{

}


void DicomDataAdapter::ConvertToAvi()
{

}

void DicomDataAdapter::setCurrentFrameNumber(int newFrameNumber)
{
	DicomDataAdapter::currentFrameNumber = newFrameNumber;
}


ptr<image> DicomDataAdapter::PrepareImage(int frameNumber)
{
	ptr<imebra::image> firstImage = this->dataSet->getImage(frameNumber);

	ptr<imebra::transforms::transform> modVOILUT(new imebra::transforms::modalityVOILUT(this->dataSet));

	imbxUint32 width, height;
	firstImage->getSize(&width, &height);
	ptr<imebra::image> convertedImage(modVOILUT->allocateOutputImage(firstImage, width, height));
	modVOILUT->runTransform(firstImage, 0, 0, width, height, convertedImage, 0, 0);

	ptr<imebra::transforms::transform> myVoiLut(new imebra::transforms::VOILUT(this->dataSet));

	ptr<imebra::image> presentationImage(myVoiLut->allocateOutputImage(convertedImage, width, height));
	myVoiLut->runTransform(convertedImage, 0, 0, width, height, presentationImage, 0, 0);

	return presentationImage;
}

void DicomDataAdapter::getFrameSize(imbxUint32 frameNumber, imbxUint32& height, imbxUint32& width)
{
	std::cout << "getFrameSize" << std::endl;

	ptr<image> Image = this->dataSet->getImage(frameNumber);
	Image->getSize(&width, &height);
}

void DicomDataAdapter::getValuesMatrix(imbxUint32 frameNumber, imbxUint32 height, imbxUint32 width, int * outputMatrix)
{
	ptr<image>presentationImage =  this->PrepareImage(frameNumber);
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
		