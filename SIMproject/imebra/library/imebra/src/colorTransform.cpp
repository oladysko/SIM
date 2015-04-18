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

/*! \file colorTransform.cpp
    \brief Implementation of the base class for the color transforms.

*/

#include "../../base/include/exception.h"
#include "../include/colorTransform.h"
#include "../include/colorTransformsFactory.h"
#include "../include/image.h"


namespace puntoexe
{

namespace imebra
{

namespace transforms
{

namespace colorTransforms
{

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//
//
//
// colorTransform
//
//
//
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//
//
// Transformation
//
//
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
void colorTransform::checkColorSpaces(const std::wstring& inputHandlerColorSpace, const std::wstring& outputHandlerColorSpace)
{
	PUNTOEXE_FUNCTION_START(L"colorTransform::runTransform");

	if(inputHandlerColorSpace != getInitialColorSpace())
	{
		PUNTOEXE_THROW(colorTransformExceptionWrongColorSpace, "The image's color space cannot be handled by the transform");
	}

	if(outputHandlerColorSpace != getFinalColorSpace())
	{
		PUNTOEXE_THROW(colorTransformExceptionWrongColorSpace, "The image's color space cannot be handled by the transform");
	}

	PUNTOEXE_FUNCTION_END();
}


ptr<image> colorTransform::allocateOutputImage(ptr<image> pInputImage, imbxUint32 width, imbxUint32 height)
{
	ptr<image> newImage(new image);
	newImage->create(width, height, pInputImage->getDepth(), getFinalColorSpace(), pInputImage->getHighBit());
	return newImage;
}





///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//
//
//
// registerColorTransform
//
//
//
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//
//
// Constructor
//
//
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
registerColorTransform::registerColorTransform(ptr<colorTransform> newColorTransform)
{
	PUNTOEXE_FUNCTION_START(L"registerColorTransform::registerColorTransform");

	ptr<colorTransformsFactory> pFactory(colorTransformsFactory::getColorTransformsFactory());
	pFactory->registerTransform(newColorTransform);

	PUNTOEXE_FUNCTION_END();
}


} // namespace colorTransforms

} // namespace transforms

} // namespace imebra

} // namespace puntoexe
