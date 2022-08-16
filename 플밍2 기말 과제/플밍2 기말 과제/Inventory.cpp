#include "Inventory.h"

int Inventory::HpPotion = 0;
int Inventory::MpPotion = 0;
int Inventory::BigHpPotion = 0;
int Inventory::BigMpPotion = 0;

bool Inventory::inventory(int x,int y, Screen& screen)
{ 
	screen.setScreen(x, y, " 1.�ϱ� HP���� (ü��40%ȸ��)   ��  (���:1)");
	screen.setScreen(x, y+1, " 2.��� HP���� (ü��70%ȸ��)   ��  (���:2)");
	screen.setScreen(x, y+2, " 3.�ϱ� MP���� (����40%ȸ��)   ��  (���:3)");
	screen.setScreen(x, y+3, " 4.��� MP���� (����70%ȸ��)   ��  (���:4)");
	screen.setScreen(x, y + 6, " 5.���ư���");
	screen.setScreen(x + 28, y, HpPotion);
	screen.setScreen(x + 28, y+1, BigHpPotion);
	screen.setScreen(x + 28, y+2, MpPotion);
	screen.setScreen(x + 28, y+3, BigMpPotion);

	screen.printScreen();

	while (true) {
		switch (_getch())
		{
		case '1':
			if (HpPotion <= 0) {
				screen.printInfo("������ �����մϴ�.");
				screen.printScreen();
				return true;
			}
			else {
				int i = Hero::GetStats(HP) + Hero::GetStats(MAXHP) * 40 / 100;
				if (i > Hero::GetStats(MAXHP)) {
					screen.printInfo("ü���� ", Hero::GetStats(MAXHP) - Hero::GetStats(HP), "��ŭ ȸ���Ǿ����ϴ�.");
					Hero::SetStats(HP) = Hero::SetStats(MAXHP);
					HpPotion--;
					screen.printScreen();
				}
				else
				{
					screen.printInfo("ü���� ", Hero::GetStats(MAXHP) * 40 / 100, "��ŭ ȸ���Ǿ����ϴ�.");
					Hero::SetStats(HP) = i;
					HpPotion--;
					screen.printScreen();
				}
			}
			return false;
			break;
		case '2':
			if (BigHpPotion <= 0) {
				screen.printInfo("������ �����մϴ�.");
				screen.printScreen();
				return true;
			}
			else {
				int i = Hero::GetStats(HP) + Hero::GetStats(MAXHP) * 70 / 100;
				if (i > Hero::GetStats(MAXHP)) {
					screen.printInfo("ü���� ", Hero::GetStats(MAXHP) - Hero::GetStats(HP), "��ŭ ȸ���Ǿ����ϴ�.");
					Hero::SetStats(HP) = Hero::SetStats(MAXHP);
					BigHpPotion--;
					screen.printScreen();
				}
				else
				{
					screen.printInfo("ü���� ", Hero::GetStats(MAXHP) * 70 / 100, "��ŭ ȸ���Ǿ����ϴ�.");
					Hero::SetStats(HP) = i;
					BigHpPotion--;
					screen.printScreen();
				}
			}
			return false;
			break;
		case '3':
			if (MpPotion <= 0) {
				screen.printInfo("������ �����մϴ�.");
				screen.printScreen();
				return true;
			}
			else {
				int i = Hero::GetStats(MP) + Hero::GetStats(MAXMP) * 40 / 100;
				if (i > Hero::GetStats(MAXMP)) {
					screen.printInfo("������ ", Hero::GetStats(MAXMP) - Hero::GetStats(MP), "��ŭ ȸ���Ǿ����ϴ�.");
					Hero::SetStats(MP) = Hero::SetStats(MAXMP);
					MpPotion--;
					screen.printScreen();
				}
				else
				{
					screen.printInfo("������ ", Hero::GetStats(MAXMP) * 40 / 100, "��ŭ ȸ���Ǿ����ϴ�.");
					Hero::SetStats(MP) = i;
					MpPotion--;
					screen.printScreen();
				}
			}
			return false;
			break;
		case '4':
			if (BigMpPotion <= 0) {
				screen.printInfo("������ �����մϴ�.");
				screen.printScreen();
				return true;
			}
			else {
				int i = Hero::GetStats(MP) + Hero::GetStats(MAXMP) * 70 / 100;
				if (i > Hero::GetStats(MAXMP)) {
					screen.printInfo("������ ", Hero::GetStats(MAXMP) - Hero::GetStats(MP), "��ŭ ȸ���Ǿ����ϴ�.");
					Hero::SetStats(MP) = Hero::SetStats(MAXMP);
					BigMpPotion--;
					screen.printScreen();
				}
				else
				{
					screen.printInfo("������ ", Hero::GetStats(MAXMP) * 70 / 100, "��ŭ ȸ���Ǿ����ϴ�.");
					Hero::SetStats(MP) = i;
					BigMpPotion--;
					screen.printScreen();
				}
			}
			return false;
			break;
		case '5':
			return true;
			break;
		}
	}

}