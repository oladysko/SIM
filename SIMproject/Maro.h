#ifndef _MARO_H_
#define _MARO_H_
#include "C:/Users/CLEVO/Desktop/imebra/library/imebra/include/imebra.h"
#include "C:/Users/CLEVO/Desktop/imebra/library/base/include/configuration.h"

int imebra_test_function();

namespace puntoexe
{
	namespace imebra
	{
		namespace Maro
		{
			void getFrameSize(imbxUint32 frameNumber, std::string fileName, imbxUint32& height, imbxUint32& width);
			void getValuesMatrix(imbxUint32 frameNumber, std::string fileName, imbxUint32 height, imbxUint32 width, int * outputMatrix);
		}
	}
}

#endif