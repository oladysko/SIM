#include "Parser.h"
#include "DicomDataAdapter.h"
#include "ColorPalete.h"

namespace  ParserH
{
	void MarshalString(String ^ s, std::string& os)
	{
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	void fileNametoPath(std::string% os)
	{
		std::string tmp;
		std::size_t found = 0;
		while ((found = os.find("\\", found + 2)) != std::string::npos){
			os.insert(found, "\\");
			if (found + 2 > os.size())
				return;
		}
	}

	void getBitmap(int width, int height, Bitmap^ dicomImage, int* frame, int minPixelValue, int maxPixelValue, ColorPalete* cp)
	{
		//allocate memory for dicom data, wchih is passed to imebra function, declare some variables
		int * tmpData = new int[height *width];
		//create rectangle, special structure for storaging image data
		Drawing::Rectangle rect = Drawing::Rectangle(0,0,dicomImage->Width, dicomImage->Height);
		//lock bits of image
		BitmapData^	bmpData = dicomImage->LockBits(rect, ImageLockMode::ReadWrite, dicomImage->PixelFormat);
		//get the addres of the first line
		IntPtr ptr = bmpData->Scan0;

		//declare an array to hold the bytes of the bitmap, doesn't work for bitmaps with grayscale or other than 24 bits per pixel
		//int bytes = Math::Abs(bmpData->Stride) * dicomImage->Height;//get data size
		int bytes = dicomImage->Width * dicomImage->Height*3;
		array<Byte>^ rgbValues = gcnew array<Byte>(bytes);

		//cp->setMinMax(minPixelValue,maxPixelValue);
		unsigned char* helper;
		//normalize data to 255 in other words, make some artefacts
		for (int counter = 0; counter < rgbValues->Length; counter++){
			if (counter % 3 == 0)
				helper = cp->getRGBValues(frame[counter / 3]);
			if ((counter/3)%width>(width-10))
			{
				helper = cp->getRGBValues((height - 1 - counter / 3 / width)
					*(maxPixelValue - minPixelValue) / (height) + minPixelValue);
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