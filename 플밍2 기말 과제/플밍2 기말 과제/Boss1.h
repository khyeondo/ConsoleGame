#ifndef BOSS1_H
#define BOSS1_H
#include"Monster.h"

class Boss1 :public Monster
{
public:
	Boss1() {}
	Boss1(int CurTurn);   //현재 턴에 따라서 몬스터 스텟결정

	void SetShape();
};
#endif 