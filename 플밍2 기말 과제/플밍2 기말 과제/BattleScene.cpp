#include "BattleScene.h"

Screen BattleScene::BattleScreen(70,36);

BattleScene::BattleScene()
{
}

BattleScene::~BattleScene()
{
}

Screen* BattleScene::GetBattleScreen()
{
	return &BattleScreen;
}

int BattleScene::run()
{
	switch (BattleSystem::Battle(BattleScreen))
	{
	case true:
		//�¸���
		if (CurTurn == 20)
			return END;
		else {
			BattleScreen.ResetInfo();
			CurTurn++;
			return MAINSCENE;
			break;
		}
	case false:
		//���� ����
		return GAMEOVER;
	}
	
	return 0;
}

void BattleScene::printScreen()
{
	BattleScreen.printScreen();
}