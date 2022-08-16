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
	static void Attack(Monster* monster, Screen& BattleScreen,int times);   //기본 공격
	static void Defence(Monster* monster, Screen& BattleScreen);            //방어
	static void SkillAttack(Monster* monster, Screen& BattleScreen);        //스킬 공격
	static void UsingItem(Monster* monster, Screen& BattleScreen);          //아이템 사용
	static void MonsterAttack(Monster* monster, Screen& BattleScreen);      //몬스터 공격
	static void Ignite(Monster* monster, Screen& BattleScreen);             //FlamSword damage

	static void GetItem(Screen& BattleScreen);                              //전투 종료시 아이템 획득
	static void UpdateBattleScreen(Monster* monster, Screen& BattleScreen, int Type); //Battle화면 업데이트
	static int RandomDamage(int damage);                                    //damage +-20% 랜덤
};
#endif // !GAMESYSTEM_H