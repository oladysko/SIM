#pragma once
#include <iostream>
#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmdata/dcdatset.h"
#include "dcmtk/dcmimgle/dcmimage.h"
#include "dcmtk/oflog/appender.h"
#include "dcmtk/dcmdata/dcdatset.h"
#include "dcmtk/dcmdata/dcitem.h"

using namespace log4cplus;

class DicomDataAdapter
{
public:
	DicomDataAdapter(char* fileName);
	virtual ~DicomDataAdapter();

	DcmDataset* dataSet;
	void CreateBmp();
	void getFrameSize(Uint32 frameNumber, Uint32& height, Uint32& width);

private:

};