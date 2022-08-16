#include "TextImage.h"

TextImage::TextImage(int x, int y)
{
	SizeX = x;
	SizeY = y;

	ppTextImage = new char*[SizeY];
	for (int i = 0; i < SizeY; i++)
	{
		ppTextImage[i] = new char[SizeX];
	}

	for (int i = 0; i < SizeY; i++)
	{
		for (int j = 0; j < SizeX; j++)
		{
			ppTextImage[i][j] = ' ';
		}
	}
}

TextImage::~TextImage()   
{
	for (int i = 0; i < SizeY; i++)
	{
		delete[] ppTextImage[i];
	}                         
	delete[] ppTextImage;
}

int TextImage::getImageSizeX()
{
	return SizeX;
}

int TextImage::getImageSizeY()
{
	return SizeY;
}

char ** TextImage::getTextImage()
{
	return ppTextImage;
}

void TextImage::setTextImage(int line, string text)
{
	for (int i = 0; i < SizeX; i++)
	{
		ppTextImage[line][i] = text.at(i);
	}
}

