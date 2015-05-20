#ifndef C_palete
#define C_palete

#include <algorithm>
#include <vector>

using namespace std;

enum PaleteName
{
	GREYSCALE,
	RAINBOW,
	JET,
	STAR,
	GREENSTAR,
	CUSTOM
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
		unsigned char* calculateRGBsSTAR(int value);
		unsigned char* calculateRGBsGREENSTAR(int value);
		unsigned char* calculateRGBsCUSTOM(int value, int** customPoints, int ranges);
		unsigned char* calculateYUVs(unsigned char *rgb);
		void ColorPalete::clearLookUp();

	public:
		ColorPalete(PaleteName initialPN);
		~ColorPalete();

		void setMinMax(int min, int max);
		void switchPalette(PaleteName paname);
		void makeCustom(int** customPoints, int ranges, int size);
		unsigned char* getRGBValues(int value);
		unsigned char* getYUVValues(int value);
};

#endif