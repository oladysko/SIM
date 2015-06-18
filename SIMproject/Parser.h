#ifndef _PARSER_H_
#define _PARSER_H_

#include "DicomDataAdapter.h"
#include <string>
#include <iostream>
#include <cstddef>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;

namespace  ParserH
{
	void getBitmap(int width, int height, Bitmap^ dicomImage, int* frame, int minPixelValue, int maxPixelValue, ColorPalete* cp);
}



#endif