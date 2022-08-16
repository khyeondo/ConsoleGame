#include "BattleSystem.h"

bool BattleSystem::Shield = false;
int  BattleSystem::Ignition = 0;
bool BattleSystem::re = true;

bool BattleSystem::Battle(Screen &BattleScreen)
{
	Monster* monster = NULL;

	if (Scene::CurTurn == 10)        //10�Ͽ� �߰� ���� ����
	{
		monster = new Boss1(Scene::CurTurn);
	}
	else if (Scene::CurTurn == 20)   //20�Ͽ� ���� ���� ����
	{
		monster = new Boss2(Scene::CurTurn);
	}
	else
	{
		switch (rand() % 3) //��� ����
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

	Ignition = 0; // ��ȭ

	while (true)
	{
		re = true;
		do {
			BattleSystem::UpdateBattleScreen(monster, BattleScreen, DEFAULT);
			switch (_getch())
			{
			case '1':       //����
				Attack(monster, BattleScreen, 1);
				break;
			case '2':		//��ų ����
				SkillAttack(monster, BattleScreen);
				break;
			case '3':		//���
				Defence(monster, BattleScreen);
				
				break;
			case '4':		//������ ���
				UsingItem(monster, BattleScreen);
				break;
			default:
				break;
			}
		} while (re);

		Ignite(monster, BattleScreen);// FlamSword ��ų ��ȭ ������ 

	 	BattleSystem::UpdateBattleScreen(monster, BattleScreen, DEFAULT);

		if (monster->GetStats(HP) <= 0)    //���� ü���� ��� �����ϸ�
		{
			if (Scene::CurTurn == 20)
			{
				delete monster;
				BattleScreen.printInfo("���� ������ �����ƽ��ϴ�!");
				BattleScreen.printInfo("������ �����մϴ�.");
				Sleep(4000);
				return true;
			}
			else
			{
				delete monster;
				BattleScreen.printInfo("�¸�!");
				Hero::LevelUp(Scene::CurTurn * 2); //����ġ ȹ�� 
				GetItem(BattleScreen);
				BattleScreen.printInfo("5�� ������ �Ѿ�ϴ�.");
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
		MonsterAttack(monster, BattleScreen);  //���� ����

		if (Hero::GetStats(HP) <= 0)  //�÷��̾��� ü���� ��� �����ϸ�
		{
			delete monster;
			BattleScreen.printInfo("�÷��̾� ���");
			Sleep(3000);
			return false;
		}
	}
}

//�⺻ ����
void BattleSystem::Attack(Monster * monster, Screen & BattleScreen,int Type) 
{
	int damage = Type*(RandomDamage(Hero::GetStats(DAMAGE)) - monster->GetStats(ARMOR));
	if (damage <= 0)
		damage = 0;
	monster->Damaged(damage);
	BattleScreen.printInfo("���Ϳ��� ", damage,"�� ������!" );
	re = false;
}

//���
void BattleSystem::Defence(Monster * monster, Screen & BattleScreen)
{
	BattleScreen.printInfo("������ ����մϴ�.");
	Shield = true;
	re = false;
}

//��ų ����
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
				BattleScreen.printInfo("Bash����!");
				Attack(monster, BattleScreen, 2);
				Hero::SetStats(MP) -= 15;
				re = false;
			}
			else {
				BattleScreen.printInfo("MP����! ������ �ҹߵǾ����ϴ�.");
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
				BattleScreen.printInfo("MP����! ������ �ҹߵǾ����ϴ�.");
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
				BattleScreen.printInfo("MP����! ������ �ҹߵǾ����ϴ�.");
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

//������ ���
void BattleSystem::UsingItem(Monster * monster, Screen & BattleScreen)
{
	BattleSystem::UpdateBattleScreen(monster, BattleScreen, ITEM);
}

//���� ����
void BattleSystem::MonsterAttack(Monster * monster, Screen & BattleScreen)
{
	if (!Shield) {
		int damage = RandomDamage(monster->GetStats(DAMAGE)) - Hero::GetStats(ARMOR);
		if (damage <= 0)
			damage = 0;
		Hero::Damaged(damage);
		BattleScreen.printInfo("������ ����!  ", damage, "�� �������� �Ծ���.");
	}
	else {
		BattleScreen.printInfo("���� ���� ��� ����!");
		Shield = false;
	}

}

//FlamSword ��ȭ ������ 
void BattleSystem::Ignite(Monster * monster, Screen & BattleScreen)
{
	if (Ignition > 0) {
		int damage = Hero::GetStats(DAMAGE)/4 + 1;
		monster->Damaged(damage);
		BattleScreen.printInfo("���Ͱ� ��ž�ϴ�. ���Ͱ� ", damage, "�� �������� �Ծ����ϴ�.");
		Ignition--;
	}
}

//���� ����� ������ ȹ�� 
void BattleSystem::GetItem(Screen& BattleScreen)
{
	if (rand() % 100 <= 20) {
		Inventory::HpPotion++;
		BattleScreen.printInfo("�ϱ� HP������ ȹ���߽��ϴ�.");
	}
	if (rand() % 100 <= 20) {
		Inventory::BigHpPotion++;
		BattleScreen.printInfo("��� HP������ ȹ���߽��ϴ�.");
	}
	if (rand() % 100 <= 20) {
		Inventory::MpPotion++;
		BattleScreen.printInfo("�ϱ� MP������ ȹ���߽��ϴ�.");
	}
	if (rand() % 100 <= 20) {
		Inventory::BigMpPotion++;
		BattleScreen.printInfo("��� MP������ ȹ���߽��ϴ�.");
	}

}

//BattleScreen
void BattleSystem::UpdateBattleScreen(Monster * monster, Screen & BattleScreen, int Type)
{
	BattleScreen.ResetScreen();

	BattleScreen.setScreen(14, 3, monster->GetShape());

	BattleScreen.setScreen(0, 23, "��-----------------+-------------------��");
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
		for (int i = 0; i <= monster->GetStats(HP) / 5; i++)  //���� ü�� 5���� '��' 1���� ���
		{
			BattleScreen.setScreen(18 + 2 * i + j, Hpline, "��");   //ü���� ���� �̻��̸� ���� �ٿ� ���
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
	
		BattleScreen.setScreen(11, 28, "1:����");		 	BattleScreen.setScreen(47, 28, "2:��ų");
		BattleScreen.setScreen(11, 32, "3:���");		   	BattleScreen.setScreen(47, 32, "4:������");
		break;
	case SKILL:
		BattleScreen.setScreen(7, 27, &InGameUI::Button);   BattleScreen.setScreen(43, 27, &InGameUI::Button);
		BattleScreen.setScreen(7, 31, &InGameUI::Button);	 BattleScreen.setScreen(43, 31, &InGameUI::Button);

		BattleScreen.setScreen(11, 28, "1:Bash (MP:15");			BattleScreen.setScreen(44, 28, "2:FlamSword (MP:20");
		BattleScreen.setScreen(8, 32, "3:HolySword (MP:30");		BattleScreen.setScreen(47, 32, "4:���ư���");
		break;
	case ITEM:
		re = Inventory::inventory(1, 26, BattleScreen);
		break;
	}
	BattleScreen.printScreen();
}

//���� Damage 
int BattleSystem::RandomDamage(int damage)
{
	return damage*(rand() % 40 + 80) / 100; // +-20%
}