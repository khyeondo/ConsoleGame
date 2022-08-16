#include "Hero.h"
#include "MainScene.h"

int Hero::MaxHp = 50;
int Hero::MaxMp = 50;
int Hero::Hp = Hero::MaxHp;
int Hero::Mp = Hero::MaxMp;
int Hero::Damage = 5;
int Hero::Armor = 1;
int Hero::Level = 1;
int Hero::Exp = 0;

TextImage Hero::shape(9,10);

void Hero::SetShape()
{
	shape.setTextImage(0, "   EEZ   ");
	shape.setTextImage(1, "   ZZZ,  ");
	shape.setTextImage(2, "  yyByy  ");
	shape.setTextImage(3, " WZZZZZW ");
	shape.setTextImage(4, "Z zZ9EZ Z");
	shape.setTextImage(5, "Z wZZZZ Z");
	shape.setTextImage(6, "  zZ ZZ  ");
	shape.setTextImage(7, "  9Z ZZ  ");
	shape.setTextImage(8, "  EZ ZZ  ");
	shape.setTextImage(9, "  BZ ZZ  ");

}

TextImage * Hero::GetShape()
{
	return &shape;
}

void Hero::Damaged(int damage)
{
		Hp -= damage;
}

int & Hero::SetStats(int name)
{
	switch (name)
	{
	case HP:
		return Hp;
		break;
	case MAXHP:
		return MaxHp;
		break;
	case MP:
		return Mp;
		break;
	case MAXMP:
		return MaxMp;
		break;
	case DAMAGE:
		return Damage;
		break;
	case ARMOR:
		return Armor;
		break;
	case LEVEL:
		return Level;
	case EXP:
		return Exp;
		break;
	}
}

int Hero::GetStats(int name)
{
	switch (name)
	{
	case HP:
		return Hp;
		break;
	case MAXHP:
		return MaxHp;
		break;
	case MP:
		return Mp;
		break;
	case MAXMP:
		return MaxMp;
		break;
	case DAMAGE:
		return Damage;
		break;
	case ARMOR:
		return Armor;
		break;
	case LEVEL:
		return Level;
	case EXP:
		return Exp;
		break;
	}
}

void Hero::LevelUp(int exp)
{
	Exp += exp;
	MainScene::MainScreen.printInfo("°æÇèÄ¡", exp, " È¹µæ!");
	if (Exp >= Level*Level*3/2)
	{
		Level++;
		MaxHp += 15;  Hp = MaxHp;
		MaxMp += 3;  Mp = MaxMp;
		Damage += 5;
		Armor += 1;
		Exp = 0;
		MainScene::MainScreen.printInfo("Level Up!");
	}
}
