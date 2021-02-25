#include "gra.h"

Gra::Gra()
{
  inicjalizacja();
}

void Gra::inicjalizacja()
{
   plansza_gry.umiescWezaNaPlanszy(waz);
   stan_gry = STAN_GRA;
   
}
void Gra::GdzieJedzenie(jedzenie &owoc) {
	if (owoc.p.getx() == NULL || owoc.p.gety() == NULL) {
		jedzenie owoc;
		plansza_gry.umiescJedzenieNaPlanszy(owoc);
	}
	else
		plansza_gry.umiescJedzenieNaPlanszy(owoc);
}

void Gra::ruch()
{
  if (stan_gry==STAN_KONIEC) return;

  int dlugosc_weza = waz.pobierzDlugoscWeza();
  Punkt *elementy_weza = waz.pobierzElementyWeza();

  waz.przesunZgodnieZKierunkiem();

  // sprawdzamy czy waz nie wyladowal na scianie!
  if (plansza_gry.czySciana(elementy_weza[dlugosc_weza-1])==true)
  {
    cout << "Koniec gry!" << endl;
    stan_gry = STAN_KONIEC;
  }
  if (plansza_gry.czyJedzenie(elementy_weza[dlugosc_weza - 1] )== true)
  {
	  waz.powiekszWeza(waz);
	  owoc.przesunJedzenie();
	  punkty++;

  }
  GdzieJedzenie(owoc);
  plansza_gry.umiescWezaNaPlanszy(waz);
}



void Gra::ustawKierunekWeza(Kierunek k)
{
  waz.zmienKierunek(k);
}