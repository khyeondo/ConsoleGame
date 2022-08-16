#include "GameManager.h"

Scene* GameManager::StartS = new StartScene();

void GameManager::GameStart()
{
	system("mode con cols=100 lines=48"); //콘솔 창 크기
	srand((unsigned)time(NULL));
	InGameUI::UISetting();

	while (true)
	{
		switch (StartS->run())
		{
		case STARTSCENE:
			delete StartS;
			StartS = new StartScene;
			break;
		case MAINSCENE:
			delete StartS;
			StartS = new MainScene;
			break;
		case BATTLESCENE:
			delete StartS;
			StartS = new BattleScene;
			break;
		case CAMPSCENE:
			delete StartS;
			StartS = new CampScene;
			break;
		case GAMEOVER:
			delete StartS;
			StartS = new EndScene;
			break;
		case END:
			delete StartS;
			system("cls");
			return;
		}
	}
}