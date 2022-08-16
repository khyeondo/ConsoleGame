#ifndef MONSTERTYPE3_H
#define MONSTERTYPE3_H
#include"Monster.h"

class MonsterType3 :public Monster
{
public:
	MonsterType3() {} 
	MonsterType3(int CurTurn);   //현재 턴에 따라서 몬스터 스텟결정

	void SetShape();
};
#endif // !MONSTERTYPE3_H