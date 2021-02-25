#include "plansza.h"

Plansza::Plansza()
{
  pola = NULL;
  inicjalizuj(20, 20);
}

Plansza::Plansza(int wysokosc, int szerokosc)
{
  pola = NULL;
  inicjalizuj(wysokosc, szerokosc);
}

Plansza::Plansza(const Plansza &p)
{
  inicjalizuj(p.wysokosc, p.szerokosc);

  for (int x=0; x<szerokosc; x++)
    for (int y=0; y<wysokosc; y++)
      pola[y][x] = p.pola[y][x];
}

void Plansza::inicjalizuj(int wysokosc, int szerokosc)
{
  this->wysokosc = wysokosc;
  this->szerokosc = szerokosc;
  stworzPola();

  for (int x=0; x<szerokosc; x++)
    for (int y=0; y<wysokosc; y++)
      if (y!=0 && x!=0 && x!=(szerokosc-1) && y!=(wysokosc-1))
        pola[y][x] = PUSTE;
      else
        pola[y][x] = SCIANA;

}

bool Plansza::czySciana(Punkt p)
{
  if (pola[p.gety()][p.getx()]==SCIANA)
    return true;
  else
    return false;
}
bool Plansza::czyJedzenie(Punkt p) {
	if (pola[p.gety()][p.getx()] == JEDZENIE)
		return true;
	else
		return false;
}



void Plansza::umiescWezaNaPlanszy(Waz &waz)
{
   Punkt *elementy_weza;
   int dlugosc_weza;
   dlugosc_weza = waz.pobierzDlugoscWeza();
   elementy_weza = waz.pobierzElementyWeza();

   // najpierw usun poprzednia pozycje weza
   for (int x=0; x<szerokosc; x++)
     for (int y=0; y<wysokosc; y++)
       if (pola[y][x]==WAZ) pola[y][x] = PUSTE;

   for (int i=0; i<dlugosc_weza; i++)
   {
     pola[elementy_weza[i].gety()][elementy_weza[i].getx()] = WAZ;
   }
}

void Plansza::umiescJedzenieNaPlanszy(jedzenie &owoc)
{
	// najpierw usun poprzednia pozycje weza
	for (int x = 0; x<szerokosc; x++)
		for (int y = 0; y<wysokosc; y++)
			if (pola[y][x] == JEDZENIE) pola[y][x] = PUSTE;


	pola[owoc.p.gety()][owoc.p.getx()] = JEDZENIE;
}

void Plansza::usunPola()
{
  if (pola!=NULL)
  {
    for (int y=0; y<wysokosc; y++)
      delete []pola[y];
    delete []pola;

    pola = NULL;
  }
}

void Plansza::stworzPola()
{
  if (pola!=NULL) usunPola();

  pola = new char*[wysokosc];
  for (int i=0; i<wysokosc; i++)
    pola[i] = new char[szerokosc];
}



Plansza::~Plansza()
{
  usunPola();
}

