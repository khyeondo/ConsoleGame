#ifndef INFO_H
#define INFO_H

#include "Define.h"

class Info
{
	string info[MAXINFOLINE];  //��õ� ���ڿ� ����
	int Line;                      //��µ� �� ��
public:
	Info();
	~Info() {}

	int GetLine();
	void printInfo(string s);                       //�˸�â ���
	void printInfo(string s1, int i, string s2);    //���� ����
	 
	void SaveInfo();          //��õ� ���ڿ� ����
	void ResetLine();         //�˸�â �ʱ�ȭ
};
#endif // !INFO_H


