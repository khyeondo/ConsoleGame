#include "MonsterType1.h"

MonsterType1::MonsterType1(int CurTurn) 
	: Monster(36, 15)
{

	Hp = CurTurn*CurTurn;
	Damage = CurTurn;
	Armor = CurTurn/2;
	SetShape();
}

void MonsterType1::SetShape()
{
   shape.setTextImage(0, "                                    ");
   shape.setTextImage(1, "            ⊂_ ┐                  ");
   shape.setTextImage(2, "            　 ＼＼ Λ＿Λ          ");
   shape.setTextImage(3, "            　　 ＼ ('ㅅ')  두둠칫  ");
   shape.setTextImage(4, "            　　　 >　  (           ");
   shape.setTextImage(5, "            　　　/ 　⌒へ＼        ");
   shape.setTextImage(6, "            　　 /　　/　＼＼       ");
   shape.setTextImage(7, "            　　 /　ノ　　 ＼_つ    ");
   shape.setTextImage(8, "            　　/　/ 두둠칫         ");
   shape.setTextImage(9, "            　 /　/|                ");
  shape.setTextImage(10, "            　(　(、                ");
  shape.setTextImage(11, "            　|　|、＼              ");
  shape.setTextImage(12, "            　| / ＼ ⌒)            ");
  shape.setTextImage(13, "            　| |　　) /            ");
  shape.setTextImage(14, "            (`ノ )　　L/            ");

}
 