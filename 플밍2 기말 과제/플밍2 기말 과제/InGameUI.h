#ifndef INGAMEUI_H
#define INGAMEUI_H
#include "TextImage.h"

class InGameUI          //자주 쓰는 TextImage 따로 저장 
{
public:
	static TextImage Button;
	static TextImage Menu;
	static TextImage Info;
	static TextImage Camping;
	static TextImage GAMEOVER;
public:
	static void UISetting();
};

#endif // !INGAMEUI_H


