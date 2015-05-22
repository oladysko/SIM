#include "VideoHandler.h"
#include "ColorPalete.h"


class GlobalVariables
{
public:
	bool active = false;
	int bitmapHeight = 0, bitmapWidth = 0;
	int min = 0, max = 0;
	VideoHandler *vh;
	ColorPalete* cp;

	GlobalVariables();
	~GlobalVariables();
};