#ifndef INGAMEUI_H
#define INGAMEUI_H
#include "TextImage.h"

class InGameUI          //���� ���� TextImage ���� ���� 
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


