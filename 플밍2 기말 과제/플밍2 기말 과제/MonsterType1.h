#ifndef MONSTERTYPE1_H
#define MONSTERTYPE1_H
#include"Monster.h"

class MonsterType1 :public Monster
{
public:
	MonsterType1() {}
	MonsterType1(int CurTurn);   //현재 턴에 따라서 몬스터 스텟결정

	void SetShape();
};
#endif // !MONSTERTYPE1_H