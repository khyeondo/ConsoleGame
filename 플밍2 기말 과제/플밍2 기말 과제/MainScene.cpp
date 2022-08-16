#include "MainScene.h"

bool MainScene::First = true;

Screen MainScene::MainScreen(70, 32);

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}

int MainScene::run()
{
	Hero::SetShape();

	if (CurTurn == 10 || CurTurn == 20)  //���� ����
		MainScreen.printInfo("�տ� ������ �ִ°� ����.");

	while (true)
	{
		if (CurTurn == 10 || CurTurn == 20)  //���� ����
		{
			UpDateScreen(2);
		}
		else 
			UpDateScreen(1);

		bool re = true;

		while (re)
		{
			switch (_getch())
			{
			case '1':
				MainScreen.ResetScreen();
				MainScreen.setScreen(0, 0, "��������.......");
				printScreen();
				Sleep(1000);
				MainScreen.setScreen(0, 1, "�߸��͸� �߰��߽��ϴ�!");
				printScreen();
				Sleep(1000);
				MainScreen.ResetScreen();
				return BATTLESCENE;
				break;
			case '2':
				if(CurTurn != 10 && CurTurn != 20)
					return CAMPSCENE;
				else {
					UpDateScreen(3);
					re = false;
				}
				break;
			case '3':
				if (CurTurn != 10 && CurTurn != 20) {
					UpDateScreen(3);
					re = false;
				}
				break;
			default:
				break;
			}
		}
	}
}

void MainScene::printScreen()
{
	MainScreen.printScreen();
}

void MainScene::UpDateScreen(int Type)
{
	MainScreen.setScreen(5, 2, "���� ��:");    MainScreen.setScreen(13, 2, CurTurn);

	 MainScreen.setScreen(5, 4, "��-----------------��");
	 MainScreen.setScreen(5, 5, "��                 ��");
	 MainScreen.setScreen(5, 6, "�� Level:          ��");
	 MainScreen.setScreen(5, 7, "��                 ��");
	 MainScreen.setScreen(5, 8, "�� HP:     /       ��");
	 MainScreen.setScreen(5, 9, "��                 ��");
	MainScreen.setScreen(5, 10, "�� MP:     /       ��");
	MainScreen.setScreen(5, 11, "��                 ��");
	MainScreen.setScreen(5, 12, "�� ���·�:         ��");
	MainScreen.setScreen(5, 13, "��                 ��");
	MainScreen.setScreen(5, 14, "�� ����:         ��");
	MainScreen.setScreen(5, 15, "��                 ��");
	MainScreen.setScreen(5, 16, "��-----------------��");

  	MainScreen.setScreen(14, 6, Hero::GetStats(LEVEL));
	MainScreen.setScreen(13, 8, Hero::GetStats(HP));
	MainScreen.setScreen(19, 8, Hero::GetStats(MAXHP));
	MainScreen.setScreen(13, 10, Hero::GetStats(MP));
	MainScreen.setScreen(19, 10, Hero::GetStats(MAXMP));
	MainScreen.setScreen(15, 12, Hero::GetStats(DAMAGE));
	MainScreen.setScreen(15, 14, Hero::GetStats(ARMOR));

	MainScreen.setScreen(40, 6, Hero::GetShape());

	MainScreen.setScreen(0, 21, &InGameUI::Menu);

	switch (Type)
	{
	case 1:           
		MainScreen.setScreen(7, 23, &InGameUI::Button);    MainScreen.setScreen(43, 23, &InGameUI::Button);
		MainScreen.setScreen(7, 27, &InGameUI::Button);

		MainScreen.setScreen(11, 24, "1:����");		 	MainScreen.setScreen(47, 24, "2:�߿�");
		MainScreen.setScreen(11, 28, "3:�κ��丮");

		if (First)//ù��° ���̸�
		{
			MainScreen.printInfo("������ �����մϴ�!");
			First = false;
		}

		printScreen();
		break;
	case 2:
		MainScreen.setScreen(7, 23, &InGameUI::Button);    MainScreen.setScreen(43, 23, &InGameUI::Button);

		MainScreen.setScreen(11, 24, "1:Boss�� ���");		 	MainScreen.setScreen(47, 24, "2:�κ��丮");

		printScreen();
		break;
	case 3:
		Inventory inventory;
		inventory.inventory(1,22,MainScreen);
		break;
	}
	

	
}
