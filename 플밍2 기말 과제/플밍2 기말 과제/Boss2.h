#ifndef BOSS2_H
#define BOSS2_H
#include"Monster.h"

class Boss2 :public Monster
{
public:
	Boss2() {} 
	Boss2(int CurTurn);    //���� �Ͽ� ���� ���� ���ݰ���

	void SetShape();
};
#endif 