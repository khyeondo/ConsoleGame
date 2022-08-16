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
	static int Damage;        //���ݷ�  
 	static int Armor;         //����
	static int Exp;           //����ġ
	static TextImage shape;
public:
	Hero() {}
	~Hero() {}

	static void SetShape();
	static TextImage* GetShape();

	static void Damaged(int damage);  //����������

	static int& SetStats(int Type);   //���� ����

	static int GetStats(int name);    //Hero���� ����
	static void LevelUp(int exp);     //����ġ ȹ��,������
};

#endif // !HERO
