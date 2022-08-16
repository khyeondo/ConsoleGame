#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

#include"Define.h"
#include"Hero.h"
#include "Monster.h"
#include "Screen.h"
#include "InGameUI.h"
#include "Scene.h"
#include "Inventory.h"
#include "MonsterType1.h"
#include "MonsterType2.h"
#include "MonsterType3.h"
#include "Boss1.h"
#include "Boss2.h"

class BattleSystem
{
private:
	static bool Shield;
	static int Ignition;
	static bool re;

	enum{ DEFAULT = 1,SKILL = 2, ITEM = 3};
public:
	static bool Battle(Screen& BattleScreen);     
	static void Attack(Monster* monster, Screen& BattleScreen,int times);   //�⺻ ����
	static void Defence(Monster* monster, Screen& BattleScreen);            //���
	static void SkillAttack(Monster* monster, Screen& BattleScreen);        //��ų ����
	static void UsingItem(Monster* monster, Screen& BattleScreen);          //������ ���
	static void MonsterAttack(Monster* monster, Screen& BattleScreen);      //���� ����
	static void Ignite(Monster* monster, Screen& BattleScreen);             //FlamSword damage

	static void GetItem(Screen& BattleScreen);                              //���� ����� ������ ȹ��
	static void UpdateBattleScreen(Monster* monster, Screen& BattleScreen, int Type); //Battleȭ�� ������Ʈ
	static int RandomDamage(int damage);                                    //damage +-20% ����
};
#endif // !GAMESYSTEM_H