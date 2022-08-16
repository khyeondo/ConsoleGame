#include "InGameUI.h"

TextImage InGameUI::Button(20, 3);
TextImage InGameUI::Menu(70, 11);
TextImage InGameUI::Info(70, 1);
TextImage InGameUI::Camping(68,25);
TextImage InGameUI::GAMEOVER(67,21);

void InGameUI::UISetting()
{
	Button.setTextImage(0, "け----------------け");
	Button.setTextImage(1, "I                  I");
	Button.setTextImage(2, "け----------------け");

	Menu.setTextImage(0, "け-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+け");
	Menu.setTextImage(1, "I                                                                    I");
	Menu.setTextImage(2, "+                                                                    +");
	Menu.setTextImage(3, "I                                                                    I");
	Menu.setTextImage(4, "+                                                                    +");
	Menu.setTextImage(5, "I                                                                    I");
	Menu.setTextImage(6, "+                                                                    +");
	Menu.setTextImage(7, "I                                                                    I");
	Menu.setTextImage(8, "+                                                                    +");
	Menu.setTextImage(9, "I                                                                    I");
	Menu.setTextImage(10, "×Info-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+け");

	Info.setTextImage(0, "×Info-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+け");

	Camping.setTextImage(0, "                                                                     ");
	Camping.setTextImage(1, "                     Z                      jZZZ                     ");
	Camping.setTextImage(2, "                     Z98EDW          WjEZZZZ5,  E                    ");
	Camping.setTextImage(3, "                    8Z   wD8ZZZZZZZE9zW         9,                   ");
	Camping.setTextImage(4, "                   B Z z             ,w,         Z                   ");
	Camping.setTextImage(5, "                  8y Zj B       ,     5y         wE                  ");
	Camping.setTextImage(6, "                 j8 wZZ Z                         Z                  ");
	Camping.setTextImage(7, "            ,   ,E  9EZ  B                         Z z ZB          zZ");
	Camping.setTextImage(8, "     5   ,  D,B Z   ZZ,W E                      ,   ZZ5ZB8ZZZ88ZZZ8Z ");
	Camping.setTextImage(9, "      ZD Z5yzZZE   jEZ Z  9  ,                      yZ  w          ZZ");
   Camping.setTextImage(10, "yy5EDy8w8,5 jZ    Z8Z Z  9                          E               D");
   Camping.setTextImage(11, "            yw    ZDZ Z   8                          Z               ");
   Camping.setTextImage(12, "           z5    8zDZ jD  E  ,                        Z jZ           ");
   Camping.setTextImage(13, "          w9     ZBBZ  Z   E                           BZ            ");
   Camping.setTextImage(14, "          Z     5EDDZ  Z   Dj                      jzZZZE            ");
   Camping.setTextImage(15, "     ZZ  Z      ZzDBZ, jD   Z                   8ZZZz                ");
   Camping.setTextImage(16, "      ZWz      ,ZBDD9D  Z    Z               EZZEw                   ");
   Camping.setTextImage(17, "       8ZZZE5  99DBBzZ  Bw    8           5ZZ9                       ");
   Camping.setTextImage(18, "           WBZZZZZZE8Z   Z    yj        ZZZ                          ");
   Camping.setTextImage(19, "                   DZZZ  z     8, jZ  ZZ5                            ");
   Camping.setTextImage(20, "                      D   ZZ5   z zZZZw                              ");
   Camping.setTextImage(21, "                      ,Z   8yZZZ8ZZZ                                 ");
   Camping.setTextImage(22, "                        DzyZ     Wz                                  ");
   Camping.setTextImage(23, "                           ,                     ,                   ");
   Camping.setTextImage(24, "                    w ,  ,w   w , ww,,  ,, , ,,    w                 ");


   GAMEOVER.setTextImage(0, "     ZZZZZZZZZZZ,     EZZZZZZ      ZZZZ       ZZZZZ ZZZZZZZZZZZZZZZ");
   GAMEOVER.setTextImage(1, "   Z8ZZ             Z9ZZ   ZZ9Z    Z88ZzZy   zZ98ZZ ZE8Zy          ");
   GAMEOVER.setTextImage(2, "  wZZW8           , ZZj8   8WZZ w  Zz899ZD  ZZ988ZZ ZE8Zy          ");
   GAMEOVER.setTextImage(3, "ZZZZD            jZZZZ       ZZZZW Z888z9ZZZZ88z8ZZ ZE8Zw          ");
   GAMEOVER.setTextImage(4, "zZzZ9    8ZZZZZZ  Z88Z       Z88Z  Z88EZZZZZZZZ88ZZ ZE8ZZZZZZZZZZZ ");
   GAMEOVER.setTextImage(5, "9ZEZz       Z9EZ  Z88ZBEZZZZDZ88Z  Z8zZ   ZZ  998ZZ ZE8Z5          ");
   GAMEOVER.setTextImage(6, "B9BZz ,     Zz8Z  Z88ZzZZZZZBZ88Z  Z88Z   Z8  ZEzZZ ZE8Zj          ");
   GAMEOVER.setTextImage(7, "   ZZZZ     Zz8Z  Z88Z       Z88Z  Z8zZ       ZZzZZ ZE8Z,          ");
   GAMEOVER.setTextImage(8, "     ZZZZZZZZZZZ WZZZZ       ZZZZy ZZZZ       ZZZZZ ZZZZZZZZZZZZZZZ");
   GAMEOVER.setTextImage(9, "                                                                   ");
  GAMEOVER.setTextImage(10, "                                                                   ");
  GAMEOVER.setTextImage(11, "   EB889998zz9   ,E5DE       EDD9, ZDDDz888999999E9 9B5Dz899998B8D ");
  GAMEOVER.setTextImage(12, "   ZZZZZZZZZZZ   wZZZZ       ZZZZw ZZZZZZZZZZZZZZZZ ZZZZZZZZZZZZZ9 ");
  GAMEOVER.setTextImage(13, "ZZZZ5       ZZZZ  Z88Z       Z88Z  Z8zZ             ZE8Z,       ZZZ");
  GAMEOVER.setTextImage(14, "zZzZ9       Z88Z  Z88Z       Z88Z  Z8zZ             ZE8ZD       Z89");
  GAMEOVER.setTextImage(15, "zZzZ9       Zz8Z  ZZ9Zwz   8,Z9EZ, Z8zZyz888888Zw   ZE8Z5      8ZZZ");
  GAMEOVER.setTextImage(16, "zZzZ9       Z88Z  ZzZEZZ   ZZZZBZ, Z8zZEZZZZZZZZj   ZEzZj    zZZ9ZZ");
  GAMEOVER.setTextImage(17, "zZzZ9       Z88Z    ZZZZZZZZZZZ    Z88Z             ZEzZZZZZZZZ    ");
  GAMEOVER.setTextImage(18, "ZZZZD       ZZZZ      zZZEZZZ      Zz8Z             ZEzZw  ZZZZZZZ ");
  GAMEOVER.setTextImage(19, "  WZZjBBBB55ZZ          zZ9        ZZZZyDBBBBBBBB8z ZZZZB  5 8ZZZZW");
  GAMEOVER.setTextImage(20, "   ZZZZZZZZZZZ          BZE        ZZZZZZZZZZZZZZZZ ZZZZ8    zZZZZZ");
}               
                                                                                           

