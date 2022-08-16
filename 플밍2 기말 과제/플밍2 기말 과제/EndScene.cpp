#include "EndScene.h"

Screen EndScene::EndScreen(100, 30);  //화면 크기

EndScene::EndScene()
{
}

EndScene::~EndScene()
{
}

int EndScene::run()
{
	EndScreen.setScreen(1, 1, &InGameUI::GAMEOVER);
	printScreen();
	Sleep(4000);
	return END;
}

void EndScene::printScreen()
{
	EndScreen.printScreen();
}
