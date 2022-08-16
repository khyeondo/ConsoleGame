#ifndef TEXTIMAGE_H
#define TEXTIMAGE_H

#include"Define.h"

class TextImage
{
	char** ppTextImage;                      //2�� ���ڹ迭
	int SizeX;                               //xũ��
	int SizeY;                               //yũ��
public:
	TextImage(int x = 50, int y = 50);       //TextImageũ�� ����
	~TextImage();

	int getImageSizeX();                     //TextImage xũ�� ����
	int getImageSizeY();                     //TextImage yũ�� ����
	char** getTextImage();                   //2�� ���ڹ迭 ����

	void setTextImage(int line, string text); //TextImage����
};

#endif // !TEXTIMAGE_H
