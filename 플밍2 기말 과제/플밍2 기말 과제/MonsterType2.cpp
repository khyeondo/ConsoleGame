#include "MonsterType2.h"

MonsterType2::MonsterType2(int CurTurn)
	: Monster(38, 19)
{
	Hp = 3/2*CurTurn*CurTurn;
	Damage = 3/2 * CurTurn;
	Armor = 0;
	SetShape();
}

void MonsterType2::SetShape()
{  
	shape.setTextImage(0, "                                      ");
	shape.setTextImage(1, "                 9DDDDDDD9            ");
	shape.setTextImage(2, "            588zD5jjjjjjj5D889        ");
	shape.setTextImage(3, "           Wyyyy55yyjjjjjjjyyDD8,     ");
	shape.setTextImage(4, "         w WDy5jWjjwyjjjjjjj5Wyyyw,W  ");
	shape.setTextImage(5, "         9D555Bj    zD5jjj5DD    B98  ");
	shape.setTextImage(6, "         zjj5          jjyy           ");
	shape.setTextImage(7, "         BjjD  ,  ZZZZ5jjy5 ,, ZZZZz  ");
	shape.setTextImage(8, "      j 5jjD     ZZZZy,jy5    ZZZZZ 8 ");
	shape.setTextImage(9, "      Z5yjj5     ZEZZjwjjy ,  ZZZZ8,Z ");
   shape.setTextImage(10, "      8Wjjjy5BW      ,Wjjy5D       wZ ");
   shape.setTextImage(11, "      8Wjjjjjj5DBBDyjjjjjjj5DBBDyjjWZ ");
   shape.setTextImage(12, "      8WjjjjjjjjjjjjjjjjjjjjjjjjjjjWZ ");
   shape.setTextImage(13, "      8WjjjjjjjjjjjjjjjjjjjjjjjjjjjWZ ");
   shape.setTextImage(14, "      8WjjjjjjjjjjjjjjjjjjjjjjjjjjjWZ ");
   shape.setTextImage(15, "      8Wjy555yjjjjyyDDDyjjjjjjyyyjjWZ ");
   shape.setTextImage(16, "      8j5DW yDyjjj5,   WyjWyyzj BDyWZ ");
   shape.setTextImage(17, "      ZDWj, Ww5555B    WDD5z y  WwyDZ ");
   shape.setTextImage(18, "      By      Wyjj5    WyyjD       yz ");
}
