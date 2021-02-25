#include "kontroler.h"
#include <Windows.h>

enum POZIOM{Latwy=200, Sredni= 125, Trudny=50};
POZIOM  lvl;
Kontroler::Kontroler() : widok(&gra)
{  }
void Kontroler::wyborLVL() {
 int x = widok.poziom();
 if (x == 1)
	 lvl = Latwy;
 if (x == 2)
	 lvl = Sredni;
 if (x == 3)
	 lvl = Trudny;
}
void Kontroler::uruchom()
{
	wyborLVL();
	while (gra.zwrocStanGry() != STAN_KONIEC)
	{
		widok.wyswietl();
		Sleep(lvl);
		gra.ruch();

		if (GetAsyncKeyState(VK_UP))
			gra.ustawKierunekWeza(GORA);
		else if (GetAsyncKeyState(VK_LEFT))
			gra.ustawKierunekWeza(LEWO);
		else if (GetAsyncKeyState(VK_RIGHT))
			gra.ustawKierunekWeza(PRAWO);
		else if (GetAsyncKeyState(VK_DOWN))
			gra.ustawKierunekWeza(DOL);
		else if (GetAsyncKeyState(VK_ESCAPE))
			break;
	}
	widok.koniec();
}


