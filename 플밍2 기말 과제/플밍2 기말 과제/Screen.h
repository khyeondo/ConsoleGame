#ifndef SCREEN_H
#define SCREEN_H

#include"Define.h"
#include "Info.h"
#include"TextImage.h"


class Screen
{
	char** ppScreen;   //화면에 출력 할 2중 문자배열
	Info info;         //알림창
	int SizeX;         //가로화면 크기
	int SizeY;         //세로화면 크기
public:
	Screen(int x = DEFAULTSCEERNX, int y = DEFAULTSCEERNY); //화면 크기 설정
	~Screen();

	void printInfo(string s);                      //알림창에 문자열 출력
	void printInfo(string s1, int i, string s2);   //알림창에 정수,문자열 출력
	void ResetInfo();                              //알림창 초기화

	void ResetScreen();                            //화면 리셋
	void printScreen();                            //현재 화면 출력

	void setScreen(int x, int y, int a);		   //원히는 좌표에 int 셋팅
	void setScreen(int x, int y, char a);          //원히는 좌표에 char 셋팅
	void setScreen(int x, int y, string a);	       //원히는 좌표에 string 셋팅
	void setScreen(int x, int y, TextImage* a);	   //원히는 좌표에 TextImage 셋팅 
};

#endif // !TEXTIMAGE_H		
