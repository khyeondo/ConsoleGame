#ifndef SCREEN_H
#define SCREEN_H

#include"Define.h"
#include "Info.h"
#include"TextImage.h"


class Screen
{
	char** ppScreen;   //ȭ�鿡 ��� �� 2�� ���ڹ迭
	Info info;         //�˸�â
	int SizeX;         //����ȭ�� ũ��
	int SizeY;         //����ȭ�� ũ��
public:
	Screen(int x = DEFAULTSCEERNX, int y = DEFAULTSCEERNY); //ȭ�� ũ�� ����
	~Screen();

	void printInfo(string s);                      //�˸�â�� ���ڿ� ���
	void printInfo(string s1, int i, string s2);   //�˸�â�� ����,���ڿ� ���
	void ResetInfo();                              //�˸�â �ʱ�ȭ

	void ResetScreen();                            //ȭ�� ����
	void printScreen();                            //���� ȭ�� ���

	void setScreen(int x, int y, int a);		   //������ ��ǥ�� int ����
	void setScreen(int x, int y, char a);          //������ ��ǥ�� char ����
	void setScreen(int x, int y, string a);	       //������ ��ǥ�� string ����
	void setScreen(int x, int y, TextImage* a);	   //������ ��ǥ�� TextImage ���� 
};

#endif // !TEXTIMAGE_H		
