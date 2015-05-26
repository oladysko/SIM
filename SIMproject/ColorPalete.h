#ifndef C_palete
#define C_palete

#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

enum PaleteName
{
	GREYSCALE,
	RAINBOW,
	SYMMETRIC,
	JET,
	STAR,
	GREENSTAR,
	HOTRANDOM,
	COLDRANDOM,
	RANDOM,
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

		/*Calculates and returns RGB values corresponding to inputed value scaled to size for GrayScale*/
		unsigned char* calculateRGBsGreyScale(int value);
		/*Calculates and returns YUV values corresponding to inputed value scaled to size for GrayScale*/
		unsigned char* calculateYUVsGreyScale(int value);
		/*Calculates and returns RGB values corresponding to inputed value scaled to size for RAINBOW*/
		unsigned char* calculateRGBsRainbow(int value);
		/*Calculates and returns RGB values corresponding to inputed value scaled to size for SYMMETRIC*/
		unsigned char* calculateRGBsSymmetric(int value);
		/*Calculates and returns RGB values corresponding to inputed value scaled to size for JET*/
		unsigned char* calculateRGBsJET(int value);
		/*Calculates and returns RGB values corresponding to inputed value scaled to size for STAR*/
		unsigned char* calculateRGBsSTAR(int value);
		/*Calculates and returns RGB values corresponding to inputed value scaled to size for GREENSTAR*/
		unsigned char* calculateRGBsGREENSTAR(int value);
		/*Calculates and returns RGB values corresponding to inputed value scaled to size for Custom Palette defined by
		 *values in array customPoints, which should be of size [ranges][3]. Each line defines RGB values of one point
		 *in between linear interpolation takes place*/
		unsigned char* calculateRGBsCUSTOM(int value, int** customPoints, int ranges);
		/*calculates and returns YUV values from inputted RGB*/
		unsigned char* calculateYUVs(unsigned char *rgb);
		/*clears LookUp Tables*/
		void ColorPalete::clearLookUp();

	public:
		ColorPalete(PaleteName initialPN);
		~ColorPalete();

		/*sets minimal and maximal value. Needed to be called at least once before getRGBValues(), getYUVValues()*/
		void setMinMax(int min, int max);
		/*switches to other Palette from predefined*/
		void switchPalette(PaleteName paname);
		/*creates custom Palette from specified points, which should be of size [ranges][3]. Each line defines 
		 *RGB values of one point in between linear interpolation takes place */
		void makeCustom(int** customPoints, int ranges, int size);
		void makeHotColdCustom(int hot = 1);
		/*Saves current color palette to file*/
		void savePalette(char* fileName);
		/*returns corresponding RGB values to the value inputted*/
		unsigned char* getRGBValues(int value);
		/*returns corresponding YUV values to the value inputted*/
		unsigned char* getYUVValues(int value);
};

#endif