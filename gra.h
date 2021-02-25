#pragma once

#include "waz.h"
#include "plansza.h"
#include "jedzenie.h"

#define STAN_GRA	1
#define STAN_KONIEC	2

class Gra
{
  public:
    Gra();
    void ruch();
    void ustawKierunekWeza(Kierunek k);
	Plansza *zwrocPlansze() { return &plansza_gry;  }
	Waz *zwrocWeza() { return &waz; }
	int zwrocStanGry() { return stan_gry; }
	void GdzieJedzenie(jedzenie &owoc);
	int zwrocPunkty() { return punkty; }

  private:
	void inicjalizacja();
	int stan_gry;
    Plansza plansza_gry;
    Waz waz;
	jedzenie owoc;
	int punkty=0;
};

