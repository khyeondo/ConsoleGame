#ifndef MONSTER_H
#define MONSTER_H

#include"Define.h"
#include"TextImage.h"

class Monster
{
protected:
	int Hp;                       //���� ü��
	int Damage;                   //���� ���ݷ�
	int Armor;                    //���� ����
	TextImage shape;              //���� ���輼
public:
	Monster() {}
	Monster(int SizeX, int SizeY); //���� TextImage ũ�� ����
	virtual ~Monster() {}

	virtual void SetShape();       //���� TextImage����

	TextImage* GetShape();         //���� TextImage����   
	int GetStats(int Type);        //���� ���� ����
	void Damaged(int Damage);      //���� ����

	
};
#endif // !UNIT_H
