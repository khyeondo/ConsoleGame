#ifndef CAMP_SCENE_H
#define CAMP_SCENE_H

#include "Define.h"
#include "Scene.h"
#include "Hero.h"
#include "InGameUI.h"

class CampScene : public Scene
{
	static Screen CampScreen;
public:
	CampScene();
	~CampScene();


	void printScreen();
	int run();
};

#endif // !START_SCENE_H
