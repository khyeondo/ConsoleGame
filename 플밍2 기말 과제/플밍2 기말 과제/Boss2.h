#ifndef BOSS2_H
#define BOSS2_H
#include"Monster.h"

class Boss2 :public Monster
{
public:
	Boss2() {} 
	Boss2(int CurTurn);    //현재 턴에 따라서 몬스터 스텟결정

	void SetShape();
};
#endif 