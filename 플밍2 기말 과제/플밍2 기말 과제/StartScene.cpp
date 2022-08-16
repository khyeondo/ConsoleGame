#include "StartScene.h"

Screen StartScene::StartScreen(70,32);

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
}

int StartScene::run()
{
	StartScreen.setScreen(26, 12, "��-----------------�� ");
	StartScreen.setScreen(26, 13, "��  Game Start :1  �� ");
	StartScreen.setScreen(26, 14, "��-----------------�� ");

	StartScreen.setScreen(26, 16, "��-----------------�� ");
	StartScreen.setScreen(26, 17, "��   Game End :2   �� ");
	StartScreen.setScreen(26, 18, "��-----------------�� ");

	StartScreen.setScreen(0, 0, "�ؼ��Է½� ������ ������������ �۵� �� �� �ֽ��ϴ�.");
	StartScreen.setScreen(0, 1, "��ȭ�� Ŭ���� ������ ������������ �۵� �� �� �ֽ��ϴ�.");

	printScreen();

	while (true)
	{
		switch (_getch())
		{
		case '1':
			return MAINSCENE;
			break;
		case '2':
			return END;
			break;
		default:
			break;
		}
	}
}

void StartScene::printScreen()
{
	StartScreen.printScreen();
}
