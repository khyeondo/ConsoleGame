#ifndef MAIN_SCENE_H
#define MAIN_SCENE_H

#include "Define.h"
#include "Scene.h"
#include "Hero.h"
#include "Inventory.h"

class MainScene : public Scene
{
private:
	static bool First; 
public:
	static Screen MainScreen;
	MainScene();
	~MainScene();

	void printScreen();
	void UpDateScreen(int Type);  //선택창 변경
	int run();
};

#endif // !MAIN_SCENE_H
