#ifndef BOSS1_H
#define BOSS1_H
#include"Monster.h"

class Boss1 :public Monster
{
public:
	Boss1() {}
	Boss1(int CurTurn);   //���� �Ͽ� ���� ���� ���ݰ���

	void SetShape();
};
#endif 