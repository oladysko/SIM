#include "DicomDataAdapter.h"
#include <iostream>
#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmimgle/dcmimage.h"
#include "dcmtk/dcmimage/diregist.h"
#include "dcmtk/dcmjpeg/djencode.h"
#include "dcmtk/dcmjpeg/djdecode.h"
using namespace log4cplus;

DicomDataAdapter::DicomDataAdapter()
{
}
DicomDataAdapter::DicomDataAdapter(VideoHandler *vh)
{
	this->vh = vh;
	DJDecoderRegistration::registerCodecs();// register JPEG codecs
}


DicomDataAdapter::~DicomDataAdapter()
{

}


int DicomDataAdapter::loadDICOMImage(char* fileName)
{
	DJDecoderRegistration::registerCodecs(); // register JPEG codecs
	if (fileformat.loadFile(fileName).good())
	{
		dataSet = fileformat.getDataset();
		if (dataSet == NULL)
		{
			return 2;
		}
	}
	else
	{
		return 1;
	}

	//if (fileformat.loadFile("E:/Ax Flair - 5/IM-0001-0001.dcm").good()) checkowane w konstruktorze
	{
		//DcmDataset *dataset = fileformat.getDataset();
		int representation = -1;
		OFCondition a;
		do{
			a = dataSet->chooseRepresentation((E_TransferSyntax)(++representation), NULL);
		}while(!a.good()); //Jesli zaden nie jest dobry nieskonczona petla!!!

		Uint16 width=0, height=0, depth=0, maxTime;
		if (dataSet->canWriteXfer((E_TransferSyntax)(representation)))
		{
			DcmElement* element = NULL, *rows=NULL,*columns=NULL,*zSize=NULL,*time=NULL,*timePos=NULL;
			
			if (EC_Normal == dataSet->findAndGetElement(DCM_Rows, rows))
			{
				rows->getUint16(height);
			}
			if (EC_Normal == dataSet->findAndGetElement(DCM_Columns, columns))
			{
				columns->getUint16(width);
			}
			if (EC_Normal == dataSet->findAndGetElement(DCM_Columns, zSize))
			{
				//zSize->getUint16(depth);
				depth = 1; //dla chetnych znalezc tag DICOMu dzieki ktoremu to zadziala
			}
			else{
				depth = 1;
			}
			if (EC_Normal == dataSet->findAndGetElement(DCM_NumberOfFrames, time))
			{
				time->getUint16(maxTime);
				if (maxTime == 0)
					maxTime=1;
				maxTime = 1;
			}
			else{
				maxTime = 1;
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
						      return 3;
					    Uint8* pixData = NULL;
					    // Get the length of this pixel item (i.e. fragment, i.e. most of the time, the lenght of the frame)
						    Uint32 length = pixitem->getLength();
					    if (length == 0)
						      return 4;
					    // Finally, get the compressed data for this pixel item
						a = pixitem->getUint8Array(pixData);
					    // Do something useful with pixData...
						if (a == EC_Normal)
						{
							if (!(vh->checkDimensions()))
								vh->setDimensions((int)width, (int)height);
								vh->addNewFrame(pixData); //dodaj nowego frame'a
						}
				  }else{
					  Uint16 *arr=new Uint16 [width*height*depth*maxTime];
					  a=element->getUint16Array(arr);
					  if (a == EC_Normal)
					  {
						if (!(vh->checkDimensions()))
							vh->setDimensions((int)width, (int)height);
						int* hArr;
						for (int i = 0; i < maxTime; i++)
						{
							for (int j = 0; j < depth; j++)
							{
								hArr = new int[width*height];
								for (int k = 0; k < width*height; k++)
									hArr[k] = (int)arr[i*depth*width*height+j*width*height+k];

								OFString ofs;
								Uint32 tablePosition=0;
								if (EC_Normal == dataSet->findAndGetOFString(DCM_InstanceNumber, ofs))
								{
									tablePosition=stoi(ofs.c_str());
								}
								vh->addNewFrame(hArr,(int)tablePosition); //dodaj nowego frame'a
							}
						}
					  }
				  }
			}
			else{ return 40; }//to do: make it smarter in future
		}
		else{ return 50; }//to do: make it smarter in future
	}
	return 0;
}
void DicomDataAdapter::loadTXTImage(char* fileName)
{
	list<int> framelist;
	string str, pom;
	ifstream istrm;
	int width=0,height=0,j=0;
	istrm.open(fileName);
	while (!istrm.eof())
	{
		if (getline(istrm, str))
		{
			height++;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == ' ')
				{
					if ((str[i - 1] == ',') || (str[i - 1] == ';'))
					{
						pom = str.substr(j, i - 2);
						j = i + 1;
						framelist.push_back(stoi(pom));
					}else{
						pom = str.substr(j, i - 1);
						j = i + 1;
						framelist.push_back(stoi(pom));
					}
				}else{
					if ((str[i] == ',') || (str[i] == ';'))
					{
						if (str.length()>i + 1)
						{
							if (str[i + 1] != ' ')
							{
								pom = str.substr(j, i - 1);
								j = i + 1;
								framelist.push_back(stoi(pom));
							}
						}
					}
				}
			}
		}
	}
	width = framelist.size()/height;
	istrm.close();
	int* frame = new int[framelist.size()];
	list<int>::iterator i;
	int cnt = 0;
	for (i = framelist.begin(); i != framelist.end(); ++i)
	{
		frame[cnt++] = *i;
	}
	if (!vh->checkDimensions())
		vh->setDimensions(width, height);
	vh->addNewFrame(frame);
}
void DicomDataAdapter::loadBinaryImage(char* fileName)
{
	streampos siz;
	int size,miss=8192;
	char * memblock,*dump;
	unsigned short * data;

	ifstream file(fileName, ios::in | ios::binary | ios::ate);
	if (file.is_open())
	{
		siz = file.tellg();
		size =(siz.operator-(miss));
		dump = new char[miss];
		if(!file.read(dump, miss))
		{
			ofstream ost;
			ost.open("dump2.txt");
			ost << file.gcount();
			ost.close();
		}
		delete[] dump;
		memblock = new char[size];
		file.seekg(0, ios::beg);
		if (!file.read(memblock, size))
		{
			ofstream ost;
			ost.open("dump.txt");
			ost<<file.gcount();
			ost.close();
		}
		file.close();

		data = new unsigned short[size / 2];
		for (int i = 0; i < size; i += 2)
		{
			data[i / 2] = ((unsigned short)memblock[i+1])<<8+memblock[i];
		}

		delete[] memblock;
		int mod = size/2, i = (int)(sqrt(size/2) + 1);
		while (mod != 0)
		{
			mod = size/2 % (--i);
		}
		if (!(vh->checkDimensions()))
			vh->setDimensions(i, size/2/i);
		vh->addNewFrame(data);
	}
}
void DicomDataAdapter::loadImage(char* fileName)
{
	char* extension = new char[3];
	int i = 0;
	while (fileName[i] != NULL)
	{
		extension[i % 3] = fileName[i];
		i++;
	}
	i--;
	if ((extension[i % 3] == 't') && (extension[(i - 1) % 3] == 'x') && (extension[(i - 2) % 3] == 't'))
	{
		loadTXTImage(fileName);
	}
	else{
		if ((extension[i % 3] == 'm') && (extension[(i - 1) % 3] == 'c') && (extension[(i - 2) % 3] == 'd'))
		{
			loadDICOMImage(fileName);
		}
		else{
			if (loadDICOMImage(fileName))
			{
				loadBinaryImage(fileName);
			}
		}
	}
}
		