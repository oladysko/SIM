#include "ColorPalete.h"

ColorPalete::ColorPalete(PaleteName initialPN)
{
	pn = initialPN;
	rgbLookUp = NULL;
	yuvLookUp = NULL;
	switchPalette(initialPN);
}
ColorPalete::~ColorPalete()
{
	clearLookUp();
}

unsigned char* ColorPalete::calculateRGBsGreyScale(int value)
{
	unsigned char* tab = new unsigned char[3];
	for (int i = 0; i < 3; i++)
	{
		tab[i] = value;
	}
	return tab;
}

unsigned char* ColorPalete::calculateYUVsGreyScale(int value)
{
	unsigned char* tab = new unsigned char[3];
	tab[0] = value;
	tab[1] = 127;
	tab[2] = 127;
	return tab;
}

unsigned char* ColorPalete::calculateRGBsRainbow(int value)
{
	unsigned char* tab = new unsigned char[3];
	tab[2] = value - 255; //R
	tab[1] = 255 - 2*abs( 127 - value);//G
	tab[0] = 255 - value;//B
	return tab;
}

unsigned char* ColorPalete::calculateRGBsBGR(int value)
{
	unsigned char* tab = new unsigned char[3];
	tab[2] = 255 - value; //R
	tab[1] = 255 - 2 * abs(127 - value);//G
	tab[0] = value - 255;//B
	return tab;
}

unsigned char* ColorPalete::calculateRGBsSymmetric(int value)
{
	unsigned char* tab;
	int** points = new int*[9];
	for (int i = 0; i < 9; i++)
	{
		points[i] = new int[3];
	}
	points[0][0] = 128; points[0][1] = 0; points[0][2] = 0;
	points[1][0] = 0; points[1][1] = 255; points[1][2] = 0;
	points[2][0] = 0; points[2][1] = 255; points[2][2] = 255;
	points[3][0] = 0; points[3][1] = 128; points[3][2] = 255;
	points[4][0] = 0; points[4][1] = 0; points[4][2] = 255;
	points[8][0] = 128; points[8][1] = 0; points[8][2] = 0;
	points[7][0] = 0; points[7][1] = 255; points[7][2] = 0;
	points[6][0] = 0; points[6][1] = 255; points[6][2] = 255;
	points[5][0] = 0; points[5][1] = 128; points[5][2] = 255;
	tab = calculateRGBsCUSTOM(value, points, 9);
	for (int i = 0; i < 9; i++)
	{
		delete[] points[i];
	}
	delete[] points;
	return tab;
}

unsigned char* ColorPalete::calculateRGBsJET(int value)
{
		/*0.0  -> (0, 0, 128)    (dark blue)
		  0.25 -> (0, 255, 0)    (green)
		  0.5  -> (255, 255, 0)  (yellow)
		  0.75 -> (255, 128, 0)  (orange)
		  1.0  -> (255, 0, 0)    (red)*/
	unsigned char* tab;
	int** points = new int*[5];
	for (int i = 0; i < 5; i++)
	{
		points[i] = new int[3];
	}
	points[0][0] = 128; points[0][1] = 0; points[0][2] = 0;
	points[1][0] = 0; points[1][1] = 255; points[1][2] = 0;
	points[2][0] = 0; points[2][1] = 255; points[2][2] = 255;
	points[3][0] = 0; points[3][1] = 128; points[3][2] = 255;
	points[4][0] = 0; points[4][1] = 0; points[4][2] = 255;
	tab = calculateRGBsCUSTOM(value, points, 5);
	for (int i = 0; i < 5; i++)
	{
		delete[] points[i];
	}
	delete[] points;
	return tab;
}
unsigned char* ColorPalete::calculateRGBsSTAR(int value)
{
	/*0.0  -> (128, 0, 0)    (dark red)
	0.25 -> (255, 128, 0)    (red)
	0.5  -> (255, 255, 128)  (yellow)
	0.75 -> (0, 192, 192)  (orange)
	1.0  -> (0, 128, 255)    (red)*/
	unsigned char* tab;
	int** points = new int*[5];
	for (int i = 0; i < 5; i++)
	{
		points[i] = new int[3];
	}
	points[0][0] = 0; points[0][1] = 0; points[0][2] = 128;
	points[1][0] = 0; points[1][1] = 128; points[1][2] = 255;
	points[2][0] = 128; points[2][1] = 255; points[2][2] = 255;
	points[3][0] = 192; points[3][1] = 128; points[3][2] = 128;
	points[4][0] = 255; points[4][1] = 128; points[4][2] = 0;
	tab = calculateRGBsCUSTOM(value, points, 5);
	for (int i = 0; i < 5; i++)
	{
		delete[] points[i];
	}
	delete[] points;
	return tab;
}
unsigned char* ColorPalete::calculateRGBsGREENSTAR(int value)
{
	unsigned char* tab;
	int** points = new int*[5];
	for (int i = 0; i < 5; i++)
	{
		points[i] = new int[3];
	}
	points[0][0] = 0; points[0][1] = 0; points[0][2] = 128;
	points[1][0] = 0; points[1][1] = 128; points[1][2] = 255;
	points[2][0] = 0; points[2][1] = 255; points[2][2] = 255;
	points[3][0] = 128; points[3][1] = 128; points[3][2] = 0;
	points[4][0] = 255; points[4][1] = 128; points[4][2] = 0;
	tab = calculateRGBsCUSTOM(value,points,5);
	for (int i = 0; i < 5; i++)
	{
		delete[] points[i];
	}
	delete[] points;
	return tab;
}
unsigned char* ColorPalete::calculateRGBsCUSTOM(int value, int** customPoints,int ranges)
{
	unsigned char* tab = new unsigned char[3];
	int denum = size / (ranges - 1);
	int range = value / denum;
	if (range >= ranges-1)
	{
		tab[2] = customPoints[range][2];
		tab[1] = customPoints[range][1];
		tab[0] = customPoints[range][0];
	}
	else{
		tab[2] = customPoints[range][2] + (customPoints[range + 1][2] - customPoints[range][2])
			* (value % denum) / denum;
		tab[1] = customPoints[range][1] + (customPoints[range + 1][1] - customPoints[range][1])
			* (value % denum) / denum;
		tab[0] = customPoints[range][0] + (customPoints[range + 1][0] - customPoints[range][0])
			* (value % denum) / denum;
	}
	return tab;
}

unsigned char* ColorPalete::calculateYUVs(unsigned char *rgb)
{
	unsigned char* tab = new unsigned char[3];
	tab[0] = ((66 * rgb[2] + 129 * rgb[1] + 25 * rgb[0] + 128) >> 8) + 16; //Y
	tab[1] = ((-38 * rgb[2] - 74 * rgb[1] + 112 * rgb[0] + 128) >> 8) + 128;//U
	tab[2] = ((112 * rgb[2] - 94 * rgb[1] - 18 * rgb[0] + 128) >> 8) + 128;//V
	return tab;
}

void ColorPalete::clearLookUp()
{
	if (rgbLookUp != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			delete[] rgbLookUp[i];
		}
		delete[] rgbLookUp;
	}
	if (yuvLookUp != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			delete[] yuvLookUp[i];
		}
		delete[] yuvLookUp;
	}
}

void ColorPalete::setMinMax(int min, int max)
{
	minV = min;
	maxV = max;
	switchPalette(pn);
}

void ColorPalete::switchPalette(PaleteName paname)
{
	pn = paname;
	switch (paname)
	{
		case GREYSCALE:
		{
			clearLookUp();
			size = maxV-minV+1;
			rgbLookUp = new unsigned char*[size];
			yuvLookUp = new unsigned char*[size];
			for (int i = 0; i < size; i++)
			{
				rgbLookUp[i] = calculateRGBsGreyScale(i*256/(size));
				yuvLookUp[i] = calculateYUVsGreyScale(i * 256 / (size));
			}
			break;
		}
		case RGB:
		{
			clearLookUp();
			size = maxV - minV+1;
			rgbLookUp = new unsigned char*[size];
			yuvLookUp = new unsigned char*[size];
			for (int i = 0; i < size; i++)
			{
				rgbLookUp[i] = calculateRGBsRainbow(i * 256 / (size));
				yuvLookUp[i] = calculateYUVs(rgbLookUp[i]);
			}
			break;
		}
		case BGR:
		{
			clearLookUp();
			size = maxV - minV + 1;
			rgbLookUp = new unsigned char*[size];
			yuvLookUp = new unsigned char*[size];
			for (int i = 0; i < size; i++)
			{
				rgbLookUp[i] = calculateRGBsBGR(i * 256 / (size));
				yuvLookUp[i] = calculateYUVs(rgbLookUp[i]);
			}
			break;
		}
		case SYMMETRIC:
		{
			clearLookUp();
			size = maxV - minV + 1;
			rgbLookUp = new unsigned char*[size];
			yuvLookUp = new unsigned char*[size];
			for (int i = 0; i < size; i++)
			{
				rgbLookUp[i] = calculateRGBsSymmetric(i);
				yuvLookUp[i] = calculateYUVs(rgbLookUp[i]);
			}
			break;
		}
		case JET:
		{
			clearLookUp();
			size = maxV - minV+1;
			rgbLookUp = new unsigned char*[size];
			yuvLookUp = new unsigned char*[size];
			for (int i = 0; i < size; i++)
			{
				rgbLookUp[i] = calculateRGBsJET(i);
				yuvLookUp[i] = calculateYUVs(rgbLookUp[i]);
			}
			break;
		}
		case STAR:
		{
			clearLookUp();
			size = maxV - minV+1;
			rgbLookUp = new unsigned char*[size];
			yuvLookUp = new unsigned char*[size];
			for (int i = 0; i < size; i++)
			{
				rgbLookUp[i] = calculateRGBsSTAR(i);
				yuvLookUp[i] = calculateYUVs(rgbLookUp[i]);
			}
			break;
		}
		case GREENSTAR:
		{
			clearLookUp();
			size = maxV - minV+1;
			rgbLookUp = new unsigned char*[size];
			yuvLookUp = new unsigned char*[size];
			for (int i = 0; i < size; i++)
			{
				rgbLookUp[i] = calculateRGBsGREENSTAR(i);
				yuvLookUp[i] = calculateYUVs(rgbLookUp[i]);
			}
			break;
		}
		case HOTRANDOM:
		{
			makeHotColdCustom();
			break;
		}
		case COLDRANDOM:
		{
			makeHotColdCustom(-1);
			break;
		}
		case RANDOM:
		{
			int** tab;
			tab = new int*[5];
			for (int i = 0; i < 5; i++)
			{
				tab[i] = new int[3];
				for (int j = 0; j < 3; j++)
				{
					tab[i][j] = rand() % 256; 
				}
			}
			makeCustom(tab, 5, maxV - minV+1);
			for (int i = 0; i < 5; i++)
			{
				delete[] tab[i];
			}
			delete[] tab;
			pn = RANDOM;
			break;
		}
		default:
		{

		}
	}
}
void ColorPalete::makeCustom(int** customPoints, int ranges, int size)
{
	clearLookUp();
	pn = CUSTOM;
	this->size = size;
	rgbLookUp = new unsigned char*[size];
	yuvLookUp = new unsigned char*[size];
	for (int i = 0; i < size; i++)
	{
		rgbLookUp[i] = calculateRGBsCUSTOM(i,customPoints,ranges);
		yuvLookUp[i] = calculateYUVs(rgbLookUp[i]);
	}
}
void ColorPalete::makeHotColdCustom(int hot)
{
	int** tab;
	int s = rand()%15+3;
	tab = new int*[s];
	for (int i = 0; i < s; i++)
	{
		tab[i] = new int[3];
		for (int j = 0; j < 3; j++)
		{
			tab[i][j] = rand() % 256;
		}
	}
	//sorting. blue is interpreted as cold, and red as hot
	int* ptr;
	for (int i = 0; i < s; i++)
	{
		for (int j = i; j < s; j++)
		{
			if (hot*tab[j][2] + 255 - hot*tab[j][0] < hot*tab[i][2] + 255 - hot*tab[i][0])
			{
				ptr = tab[i];
				tab[i] = tab[j];
				tab[j] = ptr;
			}
		}
	}

	makeCustom(tab, s, maxV - minV + 1);
	for (int i = 0; i < s; i++)
	{
		delete[] tab[i];
	}
	delete[] tab;
	if (hot > 0)
		pn = HOTRANDOM;
	else
		pn = COLDRANDOM;
	this->size = size;
}
void ColorPalete::savePalette(char* fileName)
{
	ofstream myfile;
	myfile.open(fileName);
	for (int i = 0; i < size; i++)
	{
		myfile << to_string(rgbLookUp[i][0]) << ' ' << to_string(rgbLookUp[i][1]) << ' ' << to_string(rgbLookUp[i][2]) << endl;
	}
	myfile.close();
}
unsigned char* ColorPalete::getRGBValues(int value)
{
	return rgbLookUp[value-minV];
}
unsigned char* ColorPalete::getYUVValues(int value)
{
	return yuvLookUp[value-minV];
}