#ifndef START_SCENE_H
#define START_SCENE_H

#include "Define.h"
#include "Scene.h"

class StartScene : public Scene
{
	static Screen StartScreen;
public:
	StartScene();
	~StartScene();


	void printScreen();
	int run();
};	

#endif // !START_SCENE_H
