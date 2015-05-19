#ifndef C_palete
#define C_palete

#include <algorithm>

using namespace std;

enum PaleteName
{
	GREYSCALE,
	HOTIRON,
	COLD,
	RAINBOW,
	JET
};
class ColorPalete
{
	private:
		PaleteName pn;
		int size = 0;
		unsigned char** rgbLookUp;
		unsigned char** yuvLookUp;
		int maxV, minV;

		unsigned char* calculateRGBsGreyScale(int value);
		unsigned char* calculateYUVsGreyScale(int value);
		unsigned char* calculateRGBsRainbow(int value);
		unsigned char* calculateRGBsJET(int value);
		unsigned char* calculateYUVs(unsigned char *rgb);

	public:
		ColorPalete(PaleteName initialPN);
		~ColorPalete();

		void setMinMax(int min, int max);
		void switchPalette(PaleteName paname);
		unsigned char* getRGBValues(int value);
		unsigned char* getYUVValues(int value);
};

#endif