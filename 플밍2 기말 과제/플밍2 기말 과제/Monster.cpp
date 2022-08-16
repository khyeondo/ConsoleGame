#include "Monster.h"

Monster::Monster(int SizeX,int SizeY)
	:shape(SizeX, SizeY)
{
}

void Monster::SetShape()
{
}

TextImage* Monster::GetShape()
{
	return &shape;
}

int Monster::GetStats(int command)
{
	switch (command)
	{
	case HP:
		return Hp;
		break;
	case DAMAGE:
		return Damage;
		break;
	case ARMOR:
		return Armor;
		break;
	}
}

void Monster::Damaged(int Damage)
{
	Hp -= Damage;
}

