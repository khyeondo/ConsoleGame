#ifndef INVENTORY_H
#define INVENTORY_H

#include "Screen.h"
#include "Hero.h"
class Inventory
{
public:
	//아이템 갯수
	static int HpPotion;       
	static int BigHpPotion;
	static int MpPotion;
	static int BigMpPotion;

	static bool inventory(int x,int y,Screen& screen);   //인벤토리 창 출력 밑 동작
};

#endif