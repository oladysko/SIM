#pragma once
#include <iostream>
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

class DicomDataAdapter
{
public:
	DcmFileFormat fileformat;
	VideoHandler *vh;

	DicomDataAdapter(char* fileName, VideoHandler *vh);
	virtual ~DicomDataAdapter();

	DcmDataset* dataSet;
	void CreateBmp();
	void getFrameSize(Uint32 frameNumber, Uint32& height, Uint32& width);

private:

};