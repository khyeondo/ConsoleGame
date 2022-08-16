#include "Boss2.h"

Boss2::Boss2(int CurTurn)
	: Monster(51, 22)
{
	Hp = 500;
	Damage = 20;
	Armor = 20;
	SetShape();
}

void Boss2::SetShape()
{
	shape.setTextImage(0, "        wy                                         ");
	shape.setTextImage(1, "         zZ5          WyW                          ");
	shape.setTextImage(2, "           ZZZw         WEZZZZE                    ");
	shape.setTextImage(3, "             ,ZZZZj           wZZD                 ");
	shape.setTextImage(4, "                 zZZZZZ5       ZZZZZ               ");
	shape.setTextImage(5, "                      EZZZZZZZZZDEZZZZ             ");
	shape.setTextImage(6, "      wEZZZZZzy wZZZZZZZZZZZZZZZZ   5ZZZ           ");
	shape.setTextImage(7, "   5ZZZ5   5ZZZZZZZZZZZZZZZZZZZZZZZZZZZZD          ");
	shape.setTextImage(8, "         jZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ5    ");
	shape.setTextImage(9, "      ,8ZZZZZZZZZZZZZZZZzZZZ8WZ   Z  ZZZZZZZZZ5ZZ  ");
	shape.setTextImage(10, " WZZZZZZZZZZZZZZZZZZZw    9ZZ  EZ  ,  WZ  wZ  ZZZZ ");
	shape.setTextImage(11, "D9   ZZZZZZZZZZZZZZZ       ZZZD  5ZZ           B Z ");
	shape.setTextImage(12, "     ZZZZZZZZZZZZZZ         ZZZZj   ZZZ            ");
	shape.setTextImage(13, "    ZZZZZZZZZZZZZZZ           EZZZ5    ZZZZZZZE5   ");
	shape.setTextImage(14, "  ZZ9ZZZZZZZZZZZZZZZD            ZZZZZ        9    ");
	shape.setTextImage(15, " zZ  wZZZZZZZZZZZZZZZZZW                           ");
	shape.setTextImage(16, " W    ZZZZZZZZZZZZZZZZZZZZZB                       ");
	shape.setTextImage(17, "     ZZEZZZZZZZZZZZZZZZZZZZZZZZ9                   ");
	shape.setTextImage(18, "    8Z   ZZZZZZZZZZZZZZZZZZZZZZZZZZ                ");
	shape.setTextImage(19, "    Z      ZZZZZZZZZZZZZZZZZZZZZZZZZZ              ");
	shape.setTextImage(20, "            ZZZZZZZZZZZZZZZZZZZZZZZZZZ             ");
	shape.setTextImage(21, "             ZZZZZZZZZZZZZZZZZZZZZZZZZ             ");

}
