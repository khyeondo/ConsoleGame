#include "Boss1.h"

Boss1::Boss1(int CurTurn)
	: Monster(42, 23)
{
	Hp = 400;
	Damage = 14;
	Armor = 0;
	SetShape();
}

void Boss1::SetShape()
{
	shape.setTextImage(0, "          Www,   ZjyZZBZ ZZ ,,  w  w,   w ");
	shape.setTextImage(1, "        ,  ,   DBZZZZZZZZZZZZZ      ,5    ");
	shape.setTextImage(2, "     Www,   EZZZZZZZZZZZZZZZZZwDBZy W DW  ");
	shape.setTextImage(3, "    W,     wZZ    ZZZZZZZ    ZZZ 95  ,W   ");
	shape.setTextImage(4, ", W ,w,BZzZZZZz    ZZZZ9     ZZ9ZZZ Z8    ");
	shape.setTextImage(5, "  ,,   9y BZZZZZZZZZZZZZZZZZZZZZZ8 8E     ");
	shape.setTextImage(6, " ww , wB,ZZZZZZyD,BzBBB5   ZZZZZZZZDyZ,ww ");
	shape.setTextImage(7, "       y wZZZZZZZ        ZZzyDDZZZZ W  y, ");
	shape.setTextImage(8, "  w  ZZZZZZZZZZZZZZW55WZZZ8EZZZZz8ZZyE    ");
	shape.setTextImage(9, "    ZZZZZZz8ZZZZZZZZZZZZjZZZZZZZZZZZ E ,  ");
	shape.setTextImage(10, " , ZZZZZZZZDEZZZZZZZZZZEBZzEZ8ZZZZZZ Z    ");
	shape.setTextImage(11, "   ZZ8ZZEZZZjZZZZZZZZZZZWZ5ZDZZZWZZZZ     ");
	shape.setTextImage(12, ",  ZZjZBE9ZZBZZZZZZZZZZZDZ8Z99ZZyZZBB  ,  ");
	shape.setTextImage(13, "Ww ZZZZZZZ ZZZZZZZZZZZZZZBB8ZW9zZZ5yw W   ");
	shape.setTextImage(14, ",     ZD8 ,jZZZZZZZZZZZZZZZ9BZZZZ9 D      ");
	shape.setTextImage(15, "          ,jZZEZZZZZZZZZZZZZZZZZjB E      ");
	shape.setTextImage(16, "    ,     5BjZ9ZZZZZZZZZZZZZZZZZZ8 z   w  ");
	shape.setTextImage(17, " ,W w      Z,,yEZ9ZZZZZZZZZZZZZZZZ5Z  ,,  ");
	shape.setTextImage(18, " , wywyyWww   W 5ZZEZZZZZZZZZZZZZZ5wy     ");
	shape.setTextImage(19, " ,,,yw5wjwj  w9B5,Dw9 ZyZZZZZZZZZZZZZB ,  ");
	shape.setTextImage(20, "  ,,     , ,yjjWZWEDy  B,zZZZZZZZZZZzZ    ");
	shape.setTextImage(21, " ww        ,    ,       BBjZ, 8ZZZZZ ,w   ");
	shape.setTextImage(22, "              w                   zZZ 5 w ");
}
                                                  
