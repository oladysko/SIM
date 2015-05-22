#include "GlobalVariables.h"

GlobalVariables::GlobalVariables()
{
	cp = new ColorPalete(GREYSCALE);
	vh = new VideoHandler(cp);
}
GlobalVariables::~GlobalVariables()
{
	if (vh != NULL)
	{
		delete vh;
	}
	if (cp != NULL)
	{
		delete cp;
	}
}