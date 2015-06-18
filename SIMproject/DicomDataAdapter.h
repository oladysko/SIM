#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <fcntl.h>      /* Needed only for _O_RDWR definition */
#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <share.h>
#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmdata/dcdatset.h"
#include "dcmtk/dcmimgle/dcmimage.h"
#include "dcmtk/oflog/appender.h"
#include "dcmtk/dcmdata/dcdatset.h"
#include "dcmtk/dcmdata/dcitem.h"
#include "dcmtk/dcmdata/dcpxitem.h"
#include "VideoHandler.h"

using namespace log4cplus;
using namespace std;

class DicomDataAdapter
{
public:
	DcmFileFormat fileformat;
	VideoHandler *vh;

	DicomDataAdapter(VideoHandler *vh);
	DicomDataAdapter();
	virtual ~DicomDataAdapter();

	DcmDataset* dataSet;
	int loadDICOMImage(char* fileName);
	void loadTXTImage(char* fileName);
	void loadBinaryImage(char* fileName);
	void loadImage(char* fileName);

private:

};