#ifndef DEFINE_H
#define DEFINE_H

#define DEFAULTSCEERNX 100    //�⺻ ȭ�� ũ��
#define DEFAULTSCEERNY 100    //�⺻ ȭ�� ũ��

#define MAXINFOLINE 8         //�˸�â �ִ� ��

#include <Windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<conio.h>

enum { END = 0, STARTSCENE = 1, MAINSCENE = 2 ,BATTLESCENE = 3, CAMPSCENE = 4,GAMEOVER = 5}; //Scene�̸�
enum { HP = 1, MAXHP = 2, MP = 3, MAXMP = 4, DAMAGE = 5, ARMOR = 6 ,LEVEL = 7,EXP = 8}; //����

using namespace std;

#endif