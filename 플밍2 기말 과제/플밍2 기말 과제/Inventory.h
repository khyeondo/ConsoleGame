#ifndef INVENTORY_H
#define INVENTORY_H

#include "Screen.h"
#include "Hero.h"
class Inventory
{
public:
	//������ ����
	static int HpPotion;       
	static int BigHpPotion;
	static int MpPotion;
	static int BigMpPotion;

	static bool inventory(int x,int y,Screen& screen);   //�κ��丮 â ��� �� ����
};

#endif