#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Scene.h"
#include "StartScene.h"
#include "MainScene.h"
#include "BattleScene.h"
#include "CampScene.h"
#include "EndScene.h"

class GameManager
{
private:
	static Scene* StartS; 
public:
	static void GameStart();
};

#endif // !GAMEMANAGER_H
