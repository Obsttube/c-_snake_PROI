#include "waz.h"

Waz::Waz()
{
  dlugosc_weza = 4;
  elementy_weza = new Punkt[dlugosc_weza];
  elementy_weza[0].set(1, 1);
  elementy_weza[1].set(1, 2);
  elementy_weza[2].set(1, 3);
  elementy_weza[3].set(1, 4);

  kierunek_weza = DOL;
}

void Waz::przesunZgodnieZKierunkiem()
{
  Punkt nowe_polozenie;
  nowe_polozenie = elementy_weza[dlugosc_weza-1];
  if (kierunek_weza == DOL)
      nowe_polozenie.set(nowe_polozenie.getx(), nowe_polozenie.gety() + 1);
  if (kierunek_weza == GORA)
	  nowe_polozenie.set(nowe_polozenie.getx(), nowe_polozenie.gety() - 1);
  if (kierunek_weza == LEWO)
      nowe_polozenie.set(nowe_polozenie.getx() - 1, nowe_polozenie.gety());
  if (kierunek_weza == PRAWO)
	  nowe_polozenie.set(nowe_polozenie.getx() + 1, nowe_polozenie.gety());

  // przesun elementy weza w tablicy - ostatnie miejsce pomijamy (juz tam nie ma weza)
  for (int i=1; i<dlugosc_weza; i++)
    elementy_weza[i-1] = elementy_weza[i];

  elementy_weza[dlugosc_weza-1] = nowe_polozenie;

}
void Waz::powiekszWeza(Waz &waz) {
	int *x = new int[dlugosc_weza];
	int *y = new int[dlugosc_weza];
	for (int i = 0; i < dlugosc_weza; i++) {
		 x[dlugosc_weza - 1-i] = waz.elementy_weza[dlugosc_weza - 1-i].getx();
		 y[dlugosc_weza - 1-i] = waz.elementy_weza[dlugosc_weza - 1-i].gety();
	}

	waz.dlugosc_weza++;
	waz.elementy_weza = new Punkt[dlugosc_weza];
	if (waz.kierunek_weza == DOL) {
		waz.elementy_weza[dlugosc_weza - 1].set(x[dlugosc_weza - 2], y[dlugosc_weza - 2] + 1);
		
		for (int i =0; i< dlugosc_weza-1; i++) {
			waz.elementy_weza[dlugosc_weza -(i+ 2)].set(x[dlugosc_weza - (i + 2)], y[dlugosc_weza - (i + 2)]);
		}
	}
	if (waz.kierunek_weza == GORA) {
		waz.elementy_weza[dlugosc_weza - 1].set(x[dlugosc_weza - 2], y[dlugosc_weza - 2] - 1);
		for (int i = 0; i< dlugosc_weza-1; i++) {
			waz.elementy_weza[dlugosc_weza - (i + 2)].set(x[dlugosc_weza - (i + 2)], y[dlugosc_weza - (i + 2)]);
		}
	}
	if (waz.kierunek_weza == PRAWO) {
		waz.elementy_weza[dlugosc_weza - 1].set(x[dlugosc_weza - 2] + 1, y[dlugosc_weza - 2]);
		for (int i = 0; i< dlugosc_weza-1; i++) {
			waz.elementy_weza[dlugosc_weza - (i + 2)].set(x[dlugosc_weza - (i + 2)], y[dlugosc_weza - (i + 2)]);
		}
	}
	if (waz.kierunek_weza == LEWO) {
		waz.elementy_weza[dlugosc_weza - 1].set(x[dlugosc_weza - 2] - 1, y[dlugosc_weza - 2]);
		for (int i = 0; i< dlugosc_weza-1; i++) {
			waz.elementy_weza[dlugosc_weza - (i + 2)].set(x[dlugosc_weza -(i+ 2)], y[dlugosc_weza -(i+ 2)]);
		}
	}
	delete []x;
	delete []y;
}

void Waz::zmienKierunek(Kierunek nowy_kierunek)
{
  kierunek_weza = nowy_kierunek;
}

Waz::~Waz()
{
  delete []elementy_weza;
}



