#ifndef MONSTERTYPE3_H
#define MONSTERTYPE3_H
#include"Monster.h"

class MonsterType3 :public Monster
{
public:
	MonsterType3() {} 
	MonsterType3(int CurTurn);   //���� �Ͽ� ���� ���� ���ݰ���

	void SetShape();
};
#endif // !MONSTERTYPE3_H