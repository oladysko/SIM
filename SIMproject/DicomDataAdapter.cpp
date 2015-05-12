#include "DicomDataAdapter.h"
#include <iostream>
#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmimgle/dcmimage.h"
#include "dcmtk/dcmimage/diregist.h"
#include "dcmtk/dcmjpeg/djencode.h"
#include "dcmtk/dcmjpeg/djdecode.h"
using namespace log4cplus;

DicomDataAdapter::DicomDataAdapter(char* fileName)
{
	DJDecoderRegistration::registerCodecs();// register JPEG codecs

	if (fileformat.loadFile(fileName).good())
	{
		dataSet = fileformat.getDataset();
	}
}


DicomDataAdapter::~DicomDataAdapter()
{

}


void DicomDataAdapter::getFrameSize(Uint32 frameNumber, Uint32& height, Uint32& width)
{

}


void DicomDataAdapter::CreateBmp()
{
	DJDecoderRegistration::registerCodecs(); // register JPEG codecs


	//if (fileformat.loadFile("E:/Ax Flair - 5/IM-0001-0001.dcm").good()) checkowane w konstruktorze
	{
		DcmDataset *dataset = fileformat.getDataset();
		int representation = -1;
		OFCondition a;
		do{
			a = dataset->chooseRepresentation((E_TransferSyntax)(++representation), NULL);
		}while(!a.good()); //Jesli zaden nie jest dobry nieskonczona petla!!!

		//Nie wchodzi w tego ifa!
		if (dataset->canWriteXfer((E_TransferSyntax)(representation)))
		{
			DcmElement* element = NULL;
			if (EC_Normal == dataset->findAndGetElement(DCM_PixelData, element))
			{
				Uint32 startFragment = 0;
				Uint32 sizeF = 0;
				element->getUncompressedFrameSize(dataset, sizeF);
				Uint8 * buffer = new Uint8[int(sizeF)];
				OFString decompressedColorModel = NULL;
				DcmFileCache * cache = NULL;
				OFCondition cond = element->getUncompressedFrame(dataset, 0, startFragment, buffer, sizeF, decompressedColorModel, cache);
				cond = dataset->putAndInsertUint8Array(DCM_PixelData, buffer, sizeF, true);
				if (cond.good())
				{
					DicomImage bmImg(dataset, (E_TransferSyntax)(representation));
					if (!bmImg.writeBMP("test.bmp", 8, 0))
					{
						exit(4);//to do: make it smarter in future
					}
				}
				else{ exit(3); }//to do: make it smarter in future
			}
			else{ exit(2); }//to do: make it smarter in future
		}
		else{ exit(1); }//to do: make it smarter in future
	}
}
		