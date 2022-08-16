#include "BattleSystem.h"

bool BattleSystem::Shield = false;
int  BattleSystem::Ignition = 0;
bool BattleSystem::re = true;

bool BattleSystem::Battle(Screen &BattleScreen)
{
	Monster* monster = NULL;

	if (Scene::CurTurn == 10)        //10턴에 중간 보스 출현
	{
		monster = new Boss1(Scene::CurTurn);
	}
	else if (Scene::CurTurn == 20)   //20턴에 최종 보스 출현
	{
		monster = new Boss2(Scene::CurTurn);
	}
	else
	{
		switch (rand() % 3) //잡몹 생성
		{
		case 0:
			monster = new MonsterType1(Scene::CurTurn);
			break;
		case 1:
			monster = new MonsterType2(Scene::CurTurn);
			break;
		case 2:
			monster = new MonsterType3(Scene::CurTurn);
			break;
		}
	}

	Ignition = 0; // 점화

	while (true)
	{
		re = true;
		do {
			BattleSystem::UpdateBattleScreen(monster, BattleScreen, DEFAULT);
			switch (_getch())
			{
			case '1':       //공격
				Attack(monster, BattleScreen, 1);
				break;
			case '2':		//스킬 공격
				SkillAttack(monster, BattleScreen);
				break;
			case '3':		//방어
				Defence(monster, BattleScreen);
				
				break;
			case '4':		//아이템 사용
				UsingItem(monster, BattleScreen);
				break;
			default:
				break;
			}
		} while (re);

		Ignite(monster, BattleScreen);// FlamSword 스킬 점화 데미지 

	 	BattleSystem::UpdateBattleScreen(monster, BattleScreen, DEFAULT);

		if (monster->GetStats(HP) <= 0)    //몬스터 체력이 모두 소진하면
		{
			if (Scene::CurTurn == 20)
			{
				delete monster;
				BattleScreen.printInfo("최종 보스를 물리쳤습니다!");
				BattleScreen.printInfo("게임을 종료합니다.");
				Sleep(4000);
				return true;
			}
			else
			{
				delete monster;
				BattleScreen.printInfo("승리!");
				Hero::LevelUp(Scene::CurTurn * 2); //경험치 획득 
				GetItem(BattleScreen);
				BattleScreen.printInfo("5을 누르면 넘어갑니다.");
				while (true)
				{
					switch (_getch())
					{
					case '5':
						return true;
						break;
					default:
						break;
					}
				}
			}
		}
		Sleep(500);
		MonsterAttack(monster, BattleScreen);  //몬스터 공격

		if (Hero::GetStats(HP) <= 0)  //플레이어의 체력이 모두 소진하면
		{
			delete monster;
			BattleScreen.printInfo("플레이어 사망");
			Sleep(3000);
			return false;
		}
	}
}

//기본 공격
void BattleSystem::Attack(Monster * monster, Screen & BattleScreen,int Type) 
{
	int damage = Type*(RandomDamage(Hero::GetStats(DAMAGE)) - monster->GetStats(ARMOR));
	if (damage <= 0)
		damage = 0;
	monster->Damaged(damage);
	BattleScreen.printInfo("몬스터에게 ", damage,"의 데미지!" );
	re = false;
}

//방어
void BattleSystem::Defence(Monster * monster, Screen & BattleScreen)
{
	BattleScreen.printInfo("공격을 방어합니다.");
	Shield = true;
	re = false;
}

//스킬 공격
void BattleSystem::SkillAttack(Monster * monster, Screen & BattleScreen)
{
	BattleSystem::UpdateBattleScreen(monster, BattleScreen, SKILL);
	int re = true;
	while (re)
	{
		switch (_getch())
		{
		case '1':    //Bash
			if (Hero::GetStats(MP) >= 15)
			{
				BattleScreen.printInfo("Bash공격!");
				Attack(monster, BattleScreen, 2);
				Hero::SetStats(MP) -= 15;
				re = false;
			}
			else {
				BattleScreen.printInfo("MP부족! 공격이 불발되었습니다.");
				re = true;
			}
			break;
		case '2':    //FlamAttack
			if (Hero::GetStats(MP) >= 20)
			{
				BattleScreen.printInfo("FlamAttack!");
				Attack(monster, BattleScreen, 1);
				Hero::SetStats(MP) -= 20;
				Ignition += 4;
				re = false;
			}
			else {
				BattleScreen.printInfo("MP부족! 공격이 불발되었습니다.");
				re = true;
			}
			break;
		case '3':    //HolyAttack
			if (Hero::GetStats(MP) >= 30)
			{
				BattleScreen.printInfo("HolyAttack!");
				Attack(monster, BattleScreen, 3);
				Hero::SetStats(MP) -= 30;
				re = false;
			}
			else {
				BattleScreen.printInfo("MP부족! 공격이 불발되었습니다.");
				re = true;
			}
			break;
		case '4':
			re = false;
		
			BattleSystem::re = true;
		default:
			break;
		}
	}
}

//아이템 사용
void BattleSystem::UsingItem(Monster * monster, Screen & BattleScreen)
{
	BattleSystem::UpdateBattleScreen(monster, BattleScreen, ITEM);
}

//몬스터 공격
void BattleSystem::MonsterAttack(Monster * monster, Screen & BattleScreen)
{
	if (!Shield) {
		int damage = RandomDamage(monster->GetStats(DAMAGE)) - Hero::GetStats(ARMOR);
		if (damage <= 0)
			damage = 0;
		Hero::Damaged(damage);
		BattleScreen.printInfo("몬스터의 공격!  ", damage, "의 데미지를 입었다.");
	}
	else {
		BattleScreen.printInfo("몬스터 공격 방어 성공!");
		Shield = false;
	}

}

//FlamSword 점화 데미지 
void BattleSystem::Ignite(Monster * monster, Screen & BattleScreen)
{
	if (Ignition > 0) {
		int damage = Hero::GetStats(DAMAGE)/4 + 1;
		monster->Damaged(damage);
		BattleScreen.printInfo("몬스터가 불탑니다. 몬스터가 ", damage, "의 데미지를 입었습니다.");
		Ignition--;
	}
}

//전투 종료시 아이템 획득 
void BattleSystem::GetItem(Screen& BattleScreen)
{
	if (rand() % 100 <= 20) {
		Inventory::HpPotion++;
		BattleScreen.printInfo("하급 HP포션을 획득했습니다.");
	}
	if (rand() % 100 <= 20) {
		Inventory::BigHpPotion++;
		BattleScreen.printInfo("상급 HP포션을 획득했습니다.");
	}
	if (rand() % 100 <= 20) {
		Inventory::MpPotion++;
		BattleScreen.printInfo("하급 MP포션을 획득했습니다.");
	}
	if (rand() % 100 <= 20) {
		Inventory::BigMpPotion++;
		BattleScreen.printInfo("상급 MP포션을 획득했습니다.");
	}

}

//BattleScreen
void BattleSystem::UpdateBattleScreen(Monster * monster, Screen & BattleScreen, int Type)
{
	BattleScreen.ResetScreen();

	BattleScreen.setScreen(14, 3, monster->GetShape());

	BattleScreen.setScreen(0, 23, "ㅁ-----------------+-------------------ㅁ");
	BattleScreen.setScreen(0, 24, "I HP:      /       I");
	BattleScreen.setScreen(21, 24, "MP:      /        I");

	BattleScreen.setScreen(6, 24, Hero::GetStats(HP));
	BattleScreen.setScreen(13, 24, Hero::GetStats(MAXHP));

	BattleScreen.setScreen(25, 24, Hero::GetStats(MP));
	BattleScreen.setScreen(32, 24, Hero::GetStats(MAXMP));

	int Hpline = 1;
	int j = 0;
	
	BattleScreen.setScreen(15, Hpline, "HP:");

	if(monster->GetStats(HP) >= 0)
		for (int i = 0; i <= monster->GetStats(HP) / 5; i++)  //몬스터 체력 5마다 '♥' 1개씩 출력
		{
			BattleScreen.setScreen(18 + 2 * i + j, Hpline, "♥");   //체력이 일정 이상이면 다음 줄에 출력
			if (18 + 2 * i + j == 70 - 18) {
				Hpline++;
				j -= 36;
			}
		}

	BattleScreen.setScreen(0, 25, &InGameUI::Menu);

	
	switch (Type)
	{
	case DEFAULT:
		BattleScreen.setScreen(7, 27, &InGameUI::Button);    BattleScreen.setScreen(43, 27, &InGameUI::Button);
		BattleScreen.setScreen(7, 31, &InGameUI::Button);	 BattleScreen.setScreen(43, 31, &InGameUI::Button);
	
		BattleScreen.setScreen(11, 28, "1:공격");		 	BattleScreen.setScreen(47, 28, "2:스킬");
		BattleScreen.setScreen(11, 32, "3:방어");		   	BattleScreen.setScreen(47, 32, "4:아이템");
		break;
	case SKILL:
		BattleScreen.setScreen(7, 27, &InGameUI::Button);   BattleScreen.setScreen(43, 27, &InGameUI::Button);
		BattleScreen.setScreen(7, 31, &InGameUI::Button);	 BattleScreen.setScreen(43, 31, &InGameUI::Button);

		BattleScreen.setScreen(11, 28, "1:Bash (MP:15");			BattleScreen.setScreen(44, 28, "2:FlamSword (MP:20");
		BattleScreen.setScreen(8, 32, "3:HolySword (MP:30");		BattleScreen.setScreen(47, 32, "4:돌아가기");
		break;
	case ITEM:
		re = Inventory::inventory(1, 26, BattleScreen);
		break;
	}
	BattleScreen.printScreen();
}

//랜덤 Damage 
int BattleSystem::RandomDamage(int damage)
{
	return damage*(rand() % 40 + 80) / 100; // +-20%
}