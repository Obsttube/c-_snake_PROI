#pragma once
#include "gra.h"


class Widok
{
public:
	Widok(Gra *gra);
	void wyswietl();
	void wyswietlPunkty(Gra *gra);
	int poziom();
	void koniec();
private:
	void rysujPlansze();
	Gra *gra;
};


