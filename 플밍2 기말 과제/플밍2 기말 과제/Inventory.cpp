#include "Inventory.h"

int Inventory::HpPotion = 0;
int Inventory::MpPotion = 0;
int Inventory::BigHpPotion = 0;
int Inventory::BigMpPotion = 0;

bool Inventory::inventory(int x,int y, Screen& screen)
{ 
	screen.setScreen(x, y, " 1.하급 HP포션 (체력40%회복)   개  (사용:1)");
	screen.setScreen(x, y+1, " 2.상급 HP포션 (체력70%회복)   개  (사용:2)");
	screen.setScreen(x, y+2, " 3.하급 MP포션 (마나40%회복)   개  (사용:3)");
	screen.setScreen(x, y+3, " 4.상급 MP포션 (마나70%회복)   개  (사용:4)");
	screen.setScreen(x, y + 6, " 5.돌아가기");
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
				screen.printInfo("포션이 부족합니다.");
				screen.printScreen();
				return true;
			}
			else {
				int i = Hero::GetStats(HP) + Hero::GetStats(MAXHP) * 40 / 100;
				if (i > Hero::GetStats(MAXHP)) {
					screen.printInfo("체력이 ", Hero::GetStats(MAXHP) - Hero::GetStats(HP), "만큼 회복되었습니다.");
					Hero::SetStats(HP) = Hero::SetStats(MAXHP);
					HpPotion--;
					screen.printScreen();
				}
				else
				{
					screen.printInfo("체력이 ", Hero::GetStats(MAXHP) * 40 / 100, "만큼 회복되었습니다.");
					Hero::SetStats(HP) = i;
					HpPotion--;
					screen.printScreen();
				}
			}
			return false;
			break;
		case '2':
			if (BigHpPotion <= 0) {
				screen.printInfo("포션이 부족합니다.");
				screen.printScreen();
				return true;
			}
			else {
				int i = Hero::GetStats(HP) + Hero::GetStats(MAXHP) * 70 / 100;
				if (i > Hero::GetStats(MAXHP)) {
					screen.printInfo("체력이 ", Hero::GetStats(MAXHP) - Hero::GetStats(HP), "만큼 회복되었습니다.");
					Hero::SetStats(HP) = Hero::SetStats(MAXHP);
					BigHpPotion--;
					screen.printScreen();
				}
				else
				{
					screen.printInfo("체력이 ", Hero::GetStats(MAXHP) * 70 / 100, "만큼 회복되었습니다.");
					Hero::SetStats(HP) = i;
					BigHpPotion--;
					screen.printScreen();
				}
			}
			return false;
			break;
		case '3':
			if (MpPotion <= 0) {
				screen.printInfo("포션이 부족합니다.");
				screen.printScreen();
				return true;
			}
			else {
				int i = Hero::GetStats(MP) + Hero::GetStats(MAXMP) * 40 / 100;
				if (i > Hero::GetStats(MAXMP)) {
					screen.printInfo("마나가 ", Hero::GetStats(MAXMP) - Hero::GetStats(MP), "만큼 회복되었습니다.");
					Hero::SetStats(MP) = Hero::SetStats(MAXMP);
					MpPotion--;
					screen.printScreen();
				}
				else
				{
					screen.printInfo("마나가 ", Hero::GetStats(MAXMP) * 40 / 100, "만큼 회복되었습니다.");
					Hero::SetStats(MP) = i;
					MpPotion--;
					screen.printScreen();
				}
			}
			return false;
			break;
		case '4':
			if (BigMpPotion <= 0) {
				screen.printInfo("포션이 부족합니다.");
				screen.printScreen();
				return true;
			}
			else {
				int i = Hero::GetStats(MP) + Hero::GetStats(MAXMP) * 70 / 100;
				if (i > Hero::GetStats(MAXMP)) {
					screen.printInfo("마나가 ", Hero::GetStats(MAXMP) - Hero::GetStats(MP), "만큼 회복되었습니다.");
					Hero::SetStats(MP) = Hero::SetStats(MAXMP);
					BigMpPotion--;
					screen.printScreen();
				}
				else
				{
					screen.printInfo("마나가 ", Hero::GetStats(MAXMP) * 70 / 100, "만큼 회복되었습니다.");
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