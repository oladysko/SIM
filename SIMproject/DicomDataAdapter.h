#pragma once
#include <iostream>
#include "./imebra/library/imebra/include/imebra.h"
#include "./imebra/library/base/include/configuration.h"
using namespace puntoexe;
using namespace puntoexe::imebra;

class DicomDataAdapter
{
public:
	DicomDataAdapter(std::string fileName);
	virtual ~DicomDataAdapter();
	void ConvertToAvi();
	void setCurrentFrameNumber(int newFramNumber);
	ptr<image> PrepareImage(int frameNumber);

	ptr<puntoexe::imebra::dataSet> dataSet;
	void getFrameSize(imbxUint32 frameNumber, imbxUint32& height, imbxUint32& width);
	void getValuesMatrix(imbxUint32 frameNumber, imbxUint32 height, imbxUint32 width, int * outputMatrix);

private:
	int currentFrameNumber;

};