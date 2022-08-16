#include "CampScene.h"

Screen CampScene::CampScreen(70, 29); //화면 크기

CampScene::CampScene()
{
}

CampScene::~CampScene()
{
}

int CampScene::run()
{
	CampScreen.ResetInfo();
	CampScreen.printInfo("야영중........");
	CampScreen.setScreen(1, 3,&InGameUI::Camping);
	CampScreen.setScreen(0, 28, &InGameUI::Info);
	printScreen();
	Sleep(3000);

	int  r = rand() % 10;
	if (r > 1)
	{
		CurTurn++;
		int i = Hero::GetStats(HP) + (Hero::GetStats(MAXHP) * 40 / 100);
		if (i > Hero::GetStats(MAXHP)) {
			CampScreen.printInfo("체력이 ", Hero::GetStats(MAXHP) - Hero::GetStats(HP), "만큼 회복되었습니다.");
			Hero::SetStats(HP) = Hero::SetStats(MAXHP);
			printScreen();
		}
		else
		{
			CampScreen.printInfo("체력이 ", i, "만큼 회복되었습니다.");
			Hero::SetStats(HP) = i;
			printScreen();
		}
		i = Hero::GetStats(MP) + Hero::GetStats(MAXMP) * 40 / 100;
		if (i > Hero::GetStats(MAXMP)) {
			CampScreen.printInfo("마나가 ", Hero::GetStats(MAXMP) - Hero::GetStats(MP), "만큼 회복되었습니다.");
			Hero::SetStats(MP) = Hero::SetStats(MAXMP);
			printScreen();
		}
		else
		{
			CampScreen.printInfo("마나가", i, "만큼 회복되었습니다.");
			Hero::SetStats(MP) = i;
			printScreen();
		}
		Sleep(1000);
		return MAINSCENE;
	}
	else
	{
		CampScreen.printInfo("몬스터가 습격했다!");
		printScreen();
		Sleep(1000);
		return BATTLESCENE;
	}
	
}

void CampScene::printScreen()
{
	CampScreen.printScreen();
}