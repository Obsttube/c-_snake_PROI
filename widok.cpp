#include "widok.h"
#include <Windows.h>

Widok::Widok(Gra *gra)
{
	this->gra = gra; 
}

void Widok::rysujPlansze()
{
	HANDLE std_out = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coords; 
	coords.X = 0;
	coords.Y = 0;
	SetConsoleCursorPosition(std_out, coords);

	Plansza *plansza = gra->zwrocPlansze();

	int wysokosc = plansza->pobierzWysokosc();
	int szerokosc = plansza->pobierzSzerokosc();
	for (int z = 0; z < 5; z++) {
		cout << endl;
	}
	for (int y = 0; y < wysokosc; y++)
	{
		for (int x = 0; x < szerokosc; x++)
			cout << plansza->pobierzPole(x, y);

		cout << endl;
	}
}
void Widok::koniec() {
	cout << "Wcisnij ENTER, aby zakonczyc" << endl;
	int z;
	cin >> z;
}
int Widok::poziom() {
	int x;
	cout << "Wybierz numer poziomu," << endl;
	cout<<"ktoremu jestes w stanie podolac" << endl;
	cout << "1.Latwy" << endl;
	cout << "2.Sredni" << endl;
	cout << "3.Trudny" << endl;
	cin >> x;
	return x;
}
void Widok::wyswietlPunkty(Gra *gra) {
	cout << "PUNKTY: " << gra->zwrocPunkty() << endl;
}
void Widok::wyswietl()
{
	if (gra->zwrocStanGry() == STAN_KONIEC)
	{
		cout << gra->zwrocStanGry() << endl;
		cout << "Koniec gry!";
	}
	else
	{

		rysujPlansze();
		wyswietlPunkty(this->gra);
	}
}

