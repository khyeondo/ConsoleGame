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
	static int CurTurn;          //���� �� �� 
public:
	Scene();
	virtual ~Scene();
	

	virtual void printScreen(); //sceneȭ�� ���
	virtual int run();          //���� �Լ�
};

#endif // !SCENE_H
