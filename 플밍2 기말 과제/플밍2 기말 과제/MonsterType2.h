#ifndef MONSTERTYPE2_H
#define MONSTERTYPE2_H
#include"Monster.h"

class MonsterType2 :public Monster
{
public:
	MonsterType2() {}
	MonsterType2(int CurTurn);    //현재 턴에 따라서 몬스터 스텟결정
	 
	void SetShape();
};
#endif // !MONSTERTYPE2_H