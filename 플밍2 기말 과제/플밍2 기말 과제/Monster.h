#ifndef MONSTER_H
#define MONSTER_H

#include"Define.h"
#include"TextImage.h"

class Monster
{
protected:
	int Hp;                       //몬스터 체력
	int Damage;                   //몬스터 공격력
	int Armor;                    //몬스터 방어력
	TextImage shape;              //몬스터 생김세
public:
	Monster() {}
	Monster(int SizeX, int SizeY); //몬스터 TextImage 크기 셋팅
	virtual ~Monster() {}

	virtual void SetShape();       //몬스터 TextImage셋팅

	TextImage* GetShape();         //몬스터 TextImage리턴   
	int GetStats(int Type);        //몬스터 스텟 리턴
	void Damaged(int Damage);      //몬스터 피해

	
};
#endif // !UNIT_H
