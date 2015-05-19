#include "ColorPalete.h"

ColorPalete::ColorPalete(PaleteName initialPN)
{
	pn = initialPN;
	switchPalette(initialPN);
}

int ColorPalete::calculateRGBGreyScale(int value)
{
	int helper = (int)(((value - minV) * 255) / (maxV - minV));
	return helper << 16 + helper << 8 + helper;
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

int ColorPalete::calculateRGBRainbow(int value)
{
	int helper = (int)(((value - minV) * 255) / (maxV - minV));
	return helper - 255 << 16 + 255 - 2 * abs(127 - helper) << 8 + 255 - helper;
}

unsigned char* ColorPalete::calculateRGBsRainbow(int value)
{
	unsigned char* tab = new unsigned char[3];
	tab[2] = value - 255; //R
	tab[1] = 255 - 2*abs( 127 - value);//G
	tab[0] = 255 - value;//B
	return tab;
}
int ColorPalete::calculateRGBRGB(int value)
{
	int helper = (int)(((value - minV) * 511) / (maxV - minV));
	return min(0, helper - 255) << 16 + 255 - abs(255 - helper) << 8 + min(0, 255 - helper);
}

unsigned char* ColorPalete::calculateRGBsRGB(int value)
{
	unsigned char* tab = new unsigned char[3];
	tab[2] = max(0, value - 255); //R
	tab[1] = 255 - abs(255 - value);//G
	tab[0] = max(0, 255 - value);//B
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
			rgbLookUp = new unsigned char*[256];
			yuvLookUp = new unsigned char*[256];
			for (int i = 0; i < 256; i++)
			{
				rgbLookUp[i] = calculateRGBsGreyScale(i);
				yuvLookUp[i] = calculateYUVsGreyScale(i);
			}
			break;
		}
		case RAINBOW:
		{
			rgbLookUp = new unsigned char*[256];
			yuvLookUp = new unsigned char*[256];
			for (int i = 0; i < 256; i++)
			{
				rgbLookUp[i] = calculateRGBsRainbow(i);
				yuvLookUp[i] = calculateYUVs(rgbLookUp[i]);
			}
			break;
		}
		case RGB:
		{
			rgbLookUp = new unsigned char*[512];
			yuvLookUp = new unsigned char*[512];
			for (int i = 0; i < 512; i++)
			{
				rgbLookUp[i] = calculateRGBsRGB(i);
				yuvLookUp[i] = calculateYUVs(rgbLookUp[i]);
			}
			break;
		}
		default:
		{

		}
	}
}

int ColorPalete::getRGBValue(int value)
{
	switch (pn)
	{
		case GREYSCALE:
		{
			return calculateRGBGreyScale(value);
		}
		case RAINBOW:
		{
			return calculateRGBRainbow(value);
		}
		case RGB:
		{
			return calculateRGBRGB(value);
		}
		default:
		{
			return 0;
		}
	}
}
unsigned char* ColorPalete::getRGBValues(int value)
{
	switch (pn)
	{
		case GREYSCALE:
		{
			return rgbLookUp[(int)(((value - minV) * 255) / (maxV - minV))];
		}
		case RAINBOW:
		{
			return rgbLookUp[(int)(((value - minV) * 255) / (maxV - minV))];
		}
		case RGB:
		{
			return rgbLookUp[(int)(((value - minV) * 511) / (maxV - minV))];
		}
		default:
		{
			return 0;
		}
	}
}
unsigned char* ColorPalete::getYUVValues(int value)
{
	switch (pn)
	{
	case GREYSCALE:
	{
		return yuvLookUp[(int)(((value - minV) * 255) / (maxV - minV))];
	}
	case RAINBOW:
	{
		return yuvLookUp[(int)(((value - minV) * 255) / (maxV - minV))];
	}
	case RGB:
	{
		return yuvLookUp[(int)(((value - minV) * 511) / (maxV - minV))];
	}
	default:
	{
		return 0;
	}
	}
}