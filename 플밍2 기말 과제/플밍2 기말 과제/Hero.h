#ifndef HERO_H
#define HERO_H

#include "Define.h"
#include "TextImage.h"

class MainScene;

class Hero
{
	static int Level;
	static int Hp;           
	static int MaxHp;
	static int Mp;
	static int MaxMp;
	static int Damage;        //공격력  
 	static int Armor;         //방어력
	static int Exp;           //경험치
	static TextImage shape;
public:
	Hero() {}
	~Hero() {}

	static void SetShape();
	static TextImage* GetShape();

	static void Damaged(int damage);  //피해입을때

	static int& SetStats(int Type);   //스텟 셋팅

	static int GetStats(int name);    //Hero스텟 리턴
	static void LevelUp(int exp);     //경험치 획득,레벨업
};

#endif // !HERO
