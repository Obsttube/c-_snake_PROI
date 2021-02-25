#pragma once

#include "waz.h"
#include <stdlib.h>
#include <iostream>
#include "jedzenie.h"

#define PUSTE	' '
#define SCIANA  '#'
#define WAZ	's'
#define JEDZENIE '$'

using namespace std;

class Plansza
{
  public:
    Plansza();
    Plansza(int wysokosc, int szerokosc);
    Plansza(const Plansza &p);

    void inicjalizuj(int wysokosc, int szerokosc);
    void umiescWezaNaPlanszy(Waz &waz);
	void umiescJedzenieNaPlanszy(jedzenie &owoc);
    bool czySciana(Punkt p);
	bool czyJedzenie(Punkt p);

	int pobierzWysokosc() { return wysokosc;  }
	int pobierzSzerokosc() { return szerokosc; }
	char pobierzPole(int x, int y) { return pola[y][x]; }

    ~Plansza();
  private:
    int wysokosc;
    int szerokosc;
    
    void stworzPola();
    void usunPola();

    char **pola;

};

