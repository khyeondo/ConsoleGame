#ifndef MONSTERTYPE2_H
#define MONSTERTYPE2_H
#include"Monster.h"

class MonsterType2 :public Monster
{
public:
	MonsterType2() {}
	MonsterType2(int CurTurn);    //���� �Ͽ� ���� ���� ���ݰ���
	 
	void SetShape();
};
#endif // !MONSTERTYPE2_H