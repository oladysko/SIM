#include "ColorPalete.h"

ColorPalete::ColorPalete(PaleteName initialPN)
{
	pn = initialPN;
	switchPalette(initialPN);
}
ColorPalete::~ColorPalete()
{
	for (int i = 0; i < size; i++)
	{
		delete[] rgbLookUp[i];
		delete[] yuvLookUp[i];
	}
	delete[] rgbLookUp;
	delete[] yuvLookUp;
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
unsigned char* ColorPalete::calculateYUVs(unsigned char *rgb)
{
	unsigned char* tab = new unsigned char[3];
	tab[0] = ((66 * rgb[2] + 129 * rgb[1] + 25 * rgb[0] + 128) >> 8) + 16; //Y
	tab[1] = ((-38 * rgb[2] - 74 * rgb[1] + 112 * rgb[0] + 128) >> 8) + 128;//U
	tab[2] = ((112 * rgb[2] - 94 * rgb[1] - 18 * rgb[0] + 128) >> 8) + 128;//V
	return tab;
}

void ColorPalete::setMinMax(int min, int max)
{
	minV = min;
	maxV = max;
}

void ColorPalete::switchPalette(PaleteName paname)
{
	switch (paname)
	{
		case GREYSCALE:
		{
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
		default:
		{

		}
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