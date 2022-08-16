#ifndef BATTLE_SCENE_H
#define BATTLE_SCENE_H

#include "Define.h"
#include "Scene.h"
#include "Hero.h"
#include "Monster.h"
#include "BattleSystem.h"

class BattleScene : public Scene
{
	static Screen BattleScreen;
public:
	BattleScene();
	~BattleScene();

	Screen* GetBattleScreen();

	void printScreen();
	int run();
};

#endif // !Battle_SCENE_H
