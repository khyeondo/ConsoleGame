#include "Screen.h"

Screen::Screen(int x, int y)
{
	//2�� �迭 ���� ����
	ppScreen = new char*[y];
	for (int i = 0; i < y; i++)
	{
		ppScreen[i] = new char[x];
	}
	SizeX = x;
	SizeY = y;
	ResetScreen();
}

Screen::~Screen()
{
	for (int i = 0; i < SizeY; i++)
	{
		delete [] ppScreen[i];
	}
	delete[] ppScreen;
}

void Screen::printInfo(string s)
{
	if (info.GetLine() >= MAXINFOLINE) { //�˸�â�� 5���� ������ �˸�â �ʱ�ȭ
		info.ResetLine();
		printScreen();
	}
	info.printInfo(s);
}

void Screen::printInfo(string s1, int i, string s2)
{
	if (info.GetLine() >= MAXINFOLINE) { //�˸�â�� 5���� ������ �˸�â �ʱ�ȭ
		info.ResetLine();
		printScreen();
	}
	info.printInfo(s1,i,s2);
}

void Screen::ResetInfo()
{
	info.ResetLine();
}

void Screen::ResetScreen()
{
	//ȭ�� �ʱ�ȭ
	for (int i = 0; i < SizeY; i++)
	{
		for (int j = 0; j < SizeX; j++)
		{
			ppScreen[i][j] = ' ';
		}
	}
}

void Screen::printScreen()
{
	system	("cls");   //�ܼ�â �ʱ�ȭ

	for (int i = 0; i < SizeY; i++)
	{
		for (int j = 0; j < SizeX; j++)
		{
			cout << ppScreen[i][j];
			
		}
		cout << endl;
	}
	info.SaveInfo();
}

void Screen::setScreen(int x, int y, int a)
{
	string integer = to_string(a); 
	setScreen(x, y, integer);
}

void Screen::setScreen(int x, int y, char a)
{
	ppScreen[y][x] = a;
}

void Screen::setScreen(int x, int y, string a)
{
	for (int i = x; i < x+a.size(); i++)
		ppScreen[y][i] = a.at(i-x);
}

void Screen::setScreen(int x, int y, TextImage* a)
{
	char** ppC = a->getTextImage();
	for (int i = y; i < y+a->getImageSizeY(); i++)
	{
		for (int j = x; j < x+ a->getImageSizeX(); j++)
		{
			ppScreen[i][j] = ppC[i - y][j - x];
		}
	}
}


