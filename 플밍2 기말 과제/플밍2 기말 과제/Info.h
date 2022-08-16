#ifndef INFO_H
#define INFO_H

#include "Define.h"

class Info
{
	string info[MAXINFOLINE];  //출련된 문자열 저장
	int Line;                      //출력된 줄 수
public:
	Info();
	~Info() {}

	int GetLine();
	void printInfo(string s);                       //알림창 출력
	void printInfo(string s1, int i, string s2);    //정수 포함
	 
	void SaveInfo();          //출련된 문자열 저장
	void ResetLine();         //알림창 초기화
};
#endif // !INFO_H


