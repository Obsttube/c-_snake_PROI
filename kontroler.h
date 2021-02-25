#pragma once

#include "gra.h"
#include "widok.h"

class Kontroler
{
public:
	Kontroler();
	void uruchom();
	void wyborLVL();
private:
	Gra gra;
	Widok widok; 
};


