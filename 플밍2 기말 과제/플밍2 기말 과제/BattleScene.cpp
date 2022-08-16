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
		//승리시
		if (CurTurn == 20)
			return END;
		else {
			BattleScreen.ResetInfo();
			CurTurn++;
			return MAINSCENE;
			break;
		}
	case false:
		//게임 오버
		return GAMEOVER;
	}
	
	return 0;
}

void BattleScene::printScreen()
{
	BattleScreen.printScreen();
}