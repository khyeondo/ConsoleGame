#include "CampScene.h"

Screen CampScene::CampScreen(70, 29); //ȭ�� ũ��

CampScene::CampScene()
{
}

CampScene::~CampScene()
{
}

int CampScene::run()
{
	CampScreen.ResetInfo();
	CampScreen.printInfo("�߿���........");
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
			CampScreen.printInfo("ü���� ", Hero::GetStats(MAXHP) - Hero::GetStats(HP), "��ŭ ȸ���Ǿ����ϴ�.");
			Hero::SetStats(HP) = Hero::SetStats(MAXHP);
			printScreen();
		}
		else
		{
			CampScreen.printInfo("ü���� ", i, "��ŭ ȸ���Ǿ����ϴ�.");
			Hero::SetStats(HP) = i;
			printScreen();
		}
		i = Hero::GetStats(MP) + Hero::GetStats(MAXMP) * 40 / 100;
		if (i > Hero::GetStats(MAXMP)) {
			CampScreen.printInfo("������ ", Hero::GetStats(MAXMP) - Hero::GetStats(MP), "��ŭ ȸ���Ǿ����ϴ�.");
			Hero::SetStats(MP) = Hero::SetStats(MAXMP);
			printScreen();
		}
		else
		{
			CampScreen.printInfo("������", i, "��ŭ ȸ���Ǿ����ϴ�.");
			Hero::SetStats(MP) = i;
			printScreen();
		}
		Sleep(1000);
		return MAINSCENE;
	}
	else
	{
		CampScreen.printInfo("���Ͱ� �����ߴ�!");
		printScreen();
		Sleep(1000);
		return BATTLESCENE;
	}
	
}

void CampScene::printScreen()
{
	CampScreen.printScreen();
}