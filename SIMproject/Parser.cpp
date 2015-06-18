#include "Parser.h"
#include "DicomDataAdapter.h"
#include "ColorPalete.h"

namespace  ParserH
{
	//
	// Funkcja obs³uguj¹ca tworzenie obrazów w GUI
	//

	void getBitmap(int width, int height, Bitmap^ dicomImage, int* frame, int minPixelValue, int maxPixelValue, ColorPalete* cp)
	{
		//allocate memory for dicom data
		int * tmpData = new int[height *width];
		//create rectangle, special structure for storaging image data
		Drawing::Rectangle rect = Drawing::Rectangle(0,0,dicomImage->Width, dicomImage->Height);
		//lock bits of image
		BitmapData^	bmpData = dicomImage->LockBits(rect, ImageLockMode::ReadWrite, dicomImage->PixelFormat);
		//get the addres of the first line
		IntPtr ptr = bmpData->Scan0;

		//declare an array to hold the bytes of the bitmap
		int bytes = dicomImage->Width * dicomImage->Height*3;   // number of bytes, 3 bytes for each pixel
		array<Byte>^ rgbValues = gcnew array<Byte>(bytes);		// array of bytes

		unsigned char* helper;
		//normalize data to 255 in other words, make some artefacts
		for (int counter = 0; counter < rgbValues->Length; counter++){ //for each byte

			if (counter % 3 == 0)									// co trzeci element
				helper = cp->getRGBValues(frame[counter / 3]);		// zwraca wskaŸnik na 3 elementow¹ tablicEzawieraj¹ca wartoœci sk³adowych R, G i B

			if ((counter/3)%width>(width-10)) // pêtla robi¹ca skalEbarw z boku / na ostatnich 10 pixelach
			{
				helper = cp->getRGBValues((height - 1 - counter / 3 / width)*(maxPixelValue - minPixelValue) / (height) + minPixelValue);
			}

			rgbValues[counter] = helper[counter % 3];
		}
		
		//copy array to bitmap
		Runtime::InteropServices::Marshal::Copy(rgbValues, 0, ptr, bytes);
		//unlock bits
		dicomImage->UnlockBits(bmpData);
		//delete pointer to data
		delete[] rgbValues;
	}
}