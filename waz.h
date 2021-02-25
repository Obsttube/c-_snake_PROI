#pragma once

enum Kierunek { LEWO, PRAWO, GORA, DOL };

class Punkt
{
  public:
    Punkt() { x = 0; y = 0; }
	Punkt(int x, int y) { this->x = x; this->y = y; }
	void set(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int getx() { return x;  }
	int gety() { return y; }
private:
    int x, y;
};

class Waz
{
  public:
    Waz();
    void zmienKierunek(Kierunek nowy_kierunek);
    void przesunZgodnieZKierunkiem();
	void powiekszWeza(Waz &waz);
    Punkt *pobierzElementyWeza() { return elementy_weza; }
    int pobierzDlugoscWeza() { return dlugosc_weza; }
	
    ~Waz();    

  private:
    Kierunek kierunek_weza;
    Punkt *elementy_weza;
	int dlugosc_weza;
    
};
