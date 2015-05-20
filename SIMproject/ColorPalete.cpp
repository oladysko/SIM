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

unsigned char* ColorPalete::calculateRGBsJET(int value)
{
	unsigned char* tab = new unsigned char[3];
		/*0.0  -> (0, 0, 128)    (dark blue)
		  0.25 -> (0, 255, 0)    (green)
		  0.5  -> (255, 255, 0)  (yellow)
		  0.75 -> (255, 128, 0)  (orange)
		  1.0  -> (255, 0, 0)    (red)*/
	switch (value * 4 / 256)
	{
	case 0:
	{
		tab[2] = 0;
		tab[1] = 4 * (value % 64);
		tab[0] = 127 - value % 128;
		break;
	}
	case 1:
	{
		tab[2] = 4 * (value % 64);
		tab[1] = 255;
		tab[0] = 0;
		break;
	}
	case 2:
	{
		tab[2] = 255;
		tab[1] = 255 - 2 * (value % 64);
		tab[0] = 0;
		break;
	}
	case 3:
	{
		tab[2] = 255;
		tab[1] = 127 - 2 * (value % 64);
		tab[0] = 0;
		break;
	}
	}
	return tab;
}
unsigned char* ColorPalete::calculateRGBsSTAR(int value)
{
	unsigned char* tab = new unsigned char[3];
	/*0.0  -> (128, 0, 0)    (dark red)
	0.25 -> (255, 128, 0)    (red)
	0.5  -> (255, 255, 128)  (yellow)
	0.75 -> (0, 192, 192)  (orange)
	1.0  -> (0, 128, 255)    (red)*/
	switch (value * 4 / 256)
	{
	case 0:
	{
		tab[2] = 128 + 2 * (value % 64);
		tab[1] = 2 * (value % 64);
		tab[0] = 0;
		break;
	}
	case 1:
	{
		tab[2] = 255;
		tab[1] = 128 + 2 * (value % 64);
		tab[0] = 2 * (value % 64);
		break;
	}
	case 2:
	{
		tab[2] = 255 - 2 * (value % 64);
		tab[1] = 255 - 2 * (value % 64);
		tab[0] = 128 + (value % 64);
		break;
	}
	case 3:
	{
		tab[2] = 128 - 2 * (value % 64);
		tab[1] = 128;
		tab[0] = 192 + (value % 64);
		break;
	}
	}
	return tab;
}
unsigned char* ColorPalete::calculateRGBsGREENSTAR(int value)
{
	unsigned char* tab = new unsigned char[3];
	/*0.0  -> (128, 0, 0)    (dark red)
	0.25 -> (255, 128, 0)    (red)
	0.5  -> (255, 255, 0)  (yellow)
	0.75 -> (0, 128, 128)  (orange)
	1.0  -> (0, 128, 255)    (red)*/
	switch (value * 4 / 256)
	{
	case 0:
	{
		tab[2] = 128 + 2 * (value % 64);
		tab[1] = 2 * (value % 64);
		tab[0] = 0;
		break;
	}
	case 1:
	{
		tab[2] = 255;
		tab[1] = 128 + 2 * (value % 64);
		tab[0] = 0;
		break;
	}
	case 2:
	{
		tab[2] = 255 - 4 * (value % 64);
		tab[1] = 255 - 2 * (value % 64);
		tab[0] = 2 * (value % 64);
		break;
	}
	case 3:
	{
		tab[2] = 0;
		tab[1] = 128;
		tab[0] = 128 + 2 * (value % 64);
		break;
	}
	}
	return tab;
}
unsigned char* ColorPalete::calculateRGBsCUSTOM(int value, int** customPoints,int ranges)
{
	unsigned char* tab = new unsigned char[3];
	int range = value * (ranges - 1) / size;
	tab[2] = customPoints[range][2] + (customPoints[range + 1][2] - customPoints[range][2])
									* (value % (size / (ranges - 1))) / (size / (ranges - 1));
	tab[1] = customPoints[range][1] + (customPoints[range + 1][1] - customPoints[range][1]) 
									* (value % (size / (ranges - 1))) / (size / (ranges - 1));
	tab[0] = customPoints[range][0] + (customPoints[range + 1][0] - customPoints[range][0]) 
									* (value % (size / (ranges - 1))) / (size / (ranges - 1));
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
}

void ColorPalete::switchPalette(PaleteName paname)
{
	pn = paname;
	switch (paname)
	{
		case GREYSCALE:
		{
			clearLookUp();
			size = 256;
			rgbLookUp = new unsigned char*[size];
			yuvLookUp = new unsigned char*[size];
			for (int i = 0; i < size; i++)
			{
				rgbLookUp[i] = calculateRGBsGreyScale(i);
				yuvLookUp[i] = calculateYUVsGreyScale(i);
			}
			break;
		}
		case RAINBOW:
		{
			clearLookUp();
			size = 256;
			rgbLookUp = new unsigned char*[size];
			yuvLookUp = new unsigned char*[size];
			for (int i = 0; i < size; i++)
			{
				rgbLookUp[i] = calculateRGBsRainbow(i);
				yuvLookUp[i] = calculateYUVs(rgbLookUp[i]);
			}
			break;
		}
		case JET:
		{
			clearLookUp();
			size = 256;
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
			size = 256;
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
			size = 256;
			rgbLookUp = new unsigned char*[size];
			yuvLookUp = new unsigned char*[size];
			for (int i = 0; i < size; i++)
			{
				rgbLookUp[i] = calculateRGBsGREENSTAR(i);
				yuvLookUp[i] = calculateYUVs(rgbLookUp[i]);
			}
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
unsigned char* ColorPalete::getRGBValues(int value)
{
	return rgbLookUp[(int)(((value - minV) * (size - 1)) / (maxV - minV))];
}
unsigned char* ColorPalete::getYUVValues(int value)
{
	return yuvLookUp[(int)(((value - minV) * (size - 1)) / (maxV - minV))];
}