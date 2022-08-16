#include "MonsterType3.h"

MonsterType3::MonsterType3(int CurTurn)
	: Monster(42, 17)
{
	Hp = CurTurn*CurTurn/2;
	Damage = CurTurn;
	Armor = 2*CurTurn;
	SetShape();
}

void MonsterType3::SetShape()
{
	shape.setTextImage(0, "                                          ");
	shape.setTextImage(1, "          ZZZZ                 ZZZZ       ");
	shape.setTextImage(2, "          ZZZZ                 ZZZZ       ");
	shape.setTextImage(3, "              ZZZ           ZZZ           ");
	shape.setTextImage(4, "              ZZZ           ZZZ           ");
	shape.setTextImage(5, "          ZZZZZZZZZZZZZZZZZZZZZZZZZ       ");
	shape.setTextImage(6, "          zZZZZZZZZZZZZZZZZZZZZZZZ        ");
	shape.setTextImage(7, "       ZZZZZZZ   ZZZZZZZZZZZ   ZZZZZZZ    ");
	shape.setTextImage(8, "       ZZZZZZZ   ZZZZZZZZZZZ   ZZZZZZZ    ");
	shape.setTextImage(9, "   ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZz");
   shape.setTextImage(10, "   8ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ,");
   shape.setTextImage(11, "   zZZZ   zZZZZZZZZZZZZZZZZZZZZZZZ    ZZZ ");
   shape.setTextImage(12, "   zZZZ   ZZZZZZZZZZZZZZZZZZZZZZZZy   ZZZ ");
   shape.setTextImage(13, "   zZZZ   ZZZZ                 ZZZy   ZZZ ");
   shape.setTextImage(14, "   ZZZZ   ZZZZ                 ZZZZ   ZZZB");
   shape.setTextImage(15, "              ZZZZZZZ   ZZZZZZZ           ");
   shape.setTextImage(16, "              ZZZZZZZ   ZZZZZZZ           ");

}