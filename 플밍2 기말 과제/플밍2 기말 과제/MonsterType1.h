#ifndef MONSTERTYPE1_H
#define MONSTERTYPE1_H
#include"Monster.h"

class MonsterType1 :public Monster
{
public:
	MonsterType1() {}
	MonsterType1(int CurTurn);   //���� �Ͽ� ���� ���� ���ݰ���

	void SetShape();
};
#endif // !MONSTERTYPE1_H