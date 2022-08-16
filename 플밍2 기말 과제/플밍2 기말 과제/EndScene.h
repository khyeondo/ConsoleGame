#ifndef END_SCENE_H
#define END_SCENE_H

#include "Define.h"
#include "Scene.h"
#include "InGameUI.h"
class EndScene : public Scene
{
	static Screen EndScreen;
public:
	EndScene();
	~EndScene();


	void printScreen();
	int run();
};

#endif // !START_SCENE_H
