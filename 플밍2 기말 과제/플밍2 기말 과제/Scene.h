#ifndef SCENE_H
#define SCENE_H

#include "Define.h"
#include "Screen.h"
#include "TextImage.h"
#include "InGameUI.h"

//class GameSystem;

class Scene
{
public:
	static int CurTurn;          //현재 턴 수 
public:
	Scene();
	virtual ~Scene();
	

	virtual void printScreen(); //scene화면 출력
	virtual int run();          //실행 함수
};

#endif // !SCENE_H
