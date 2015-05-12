#include "DicomDataAdapter.h"
#include <iostream>
#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmimgle/dcmimage.h"
#include "dcmtk/dcmimage/diregist.h"
#include "dcmtk/dcmjpeg/djencode.h"
#include "dcmtk/dcmjpeg/djdecode.h"
#include "VideoHandler.h"
using namespace log4cplus;

DicomDataAdapter::DicomDataAdapter(char* fileName)
{
	DJDecoderRegistration::registerCodecs();// register JPEG codecs
	if (fileformat.loadFile(fileName).good())
	{
		dataSet = fileformat.getDataset();
		if (dataSet == NULL)
		{
			return;
		}
	}
	else
	{
		return;
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
		//DcmDataset *dataset = fileformat.getDataset();
		int representation = -1;
		OFCondition a;
		do{
			a = dataSet->chooseRepresentation((E_TransferSyntax)(++representation), NULL);
		}while(!a.good()); //Jesli zaden nie jest dobry nieskonczona petla!!!

		Uint16 width=0, height=0;
		if (dataSet->canWriteXfer((E_TransferSyntax)(representation)))
		{
			DcmElement* element = NULL, *rows=NULL,*columns=NULL;
			
			if (EC_Normal == dataSet->findAndGetElement(DCM_Rows, rows))
			{
				rows->getUint16(height);
			}
			if (EC_Normal == dataSet->findAndGetElement(DCM_Columns, columns))
			{
				columns->getUint16(width);
			}
			if (EC_Normal == dataSet->findAndGetElement(DCM_PixelData, element))
			{
				DcmPixelData *dpix = NULL;
				dpix = OFstatic_cast(DcmPixelData*, element);
				/* Since we have compressed data, we must utilize DcmPixelSequence
				     in order to access it in raw format, e. g. for decompressing it
				     with an external library.
				   */
				  DcmPixelSequence *dseq = NULL;
				  E_TransferSyntax xferSyntax = EXS_Unknown;
				  const DcmRepresentationParameter *rep = NULL;
				  // Find the key that is needed to access the right representation of the data within DCMTK
					  dpix->getOriginalRepresentationKey(xferSyntax, rep);
				  // Access original data representation and get result within pixel sequence
					  a = dpix->getEncapsulatedRepresentation(xferSyntax, rep, dseq);
				  if (a == EC_Normal)
					  {
					    DcmPixelItem* pixitem = NULL;
					    // Access first frame (skipping offset table)
						    dseq->getItem(pixitem, 1);
					    if (pixitem == NULL)
						      return;
					    Uint8* pixData = NULL;
					    // Get the length of this pixel item (i.e. fragment, i.e. most of the time, the lenght of the frame)
						    Uint32 length = pixitem->getLength();
					    if (length == 0)
						      return;
					    // Finally, get the compressed data for this pixel item
						    a = pixitem->getUint8Array(pixData);
					    // Do something useful with pixData...

							///*Moje bazgroly
							VideoHandler *vh = new VideoHandler((int)width,(int)height, 1);
							for (int i = 0; i < 20; i++)
								vh->addNewFrame(pixData); //dodaj nowego frame'a
							vh->video_encode("test2.mp4", AV_CODEC_ID_MPEG4);
							delete(vh);
							//*/
						}
			}
			else{ exit(2); }//to do: make it smarter in future
		}
		else{ exit(1); }//to do: make it smarter in future
	}
}
		