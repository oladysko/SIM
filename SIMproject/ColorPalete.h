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
	RGB
};
class ColorPalete
{
	private:
		PaleteName pn;
		unsigned char** rgbLookUp;
		unsigned char** yuvLookUp;

		int maxV, minV;
		int calculateRGBGreyScale(int value);
		unsigned char* calculateRGBsGreyScale(int value);
		unsigned char* calculateYUVsGreyScale(int value);
		int calculateRGBRainbow(int value);
		unsigned char* calculateRGBsRainbow(int value);
		int calculateRGBRGB(int value);
		unsigned char* calculateRGBsRGB(int value);
		unsigned char* calculateYUVs(unsigned char *rgb);

	public:
		ColorPalete(PaleteName initialPN);

		void setMinMax(int min, int max);
		void switchPalette(PaleteName paname);
		int getRGBValue(int value);
		unsigned char* getRGBValues(int value);
		unsigned char* getYUVValues(int value);
};

#endif