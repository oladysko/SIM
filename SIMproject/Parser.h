#ifndef _PARSER_H_
#define _PARSER_H_

#include "DicomDataAdapter.h"
#include <string>
#include <iostream>
#include <cstddef>
#include "./imebra/library/imebra/include/imebra.h"
#include "./imebra/library/base/include/configuration.h"

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;

namespace  ParserH
{
	void MarshalString(String ^ s, std::string& os);
	void fileNametoPath(std::string% os);
	void getImageSize(int& height, int& width, unsigned int frameNumber, DicomDataAdapter* dicomdata);
	void getBitmap(const int height, const int width, unsigned int frameNumber, DicomDataAdapter* dicomdata, Bitmap^ dicomImage);
}
#endif