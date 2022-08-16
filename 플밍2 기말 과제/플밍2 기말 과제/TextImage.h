#ifndef TEXTIMAGE_H
#define TEXTIMAGE_H

#include"Define.h"

class TextImage
{
	char** ppTextImage;                      //2중 문자배열
	int SizeX;                               //x크기
	int SizeY;                               //y크기
public:
	TextImage(int x = 50, int y = 50);       //TextImage크기 설정
	~TextImage();

	int getImageSizeX();                     //TextImage x크기 리턴
	int getImageSizeY();                     //TextImage y크기 리턴
	char** getTextImage();                   //2중 문자배열 리턴

	void setTextImage(int line, string text); //TextImage셋팅
};

#endif // !TEXTIMAGE_H
