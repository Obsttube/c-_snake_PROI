#include "jedzenie.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

jedzenie::jedzenie()
{
	srand(time(NULL));
	p.set((rand() % 18) + 1, (rand() % 18) + 1);
}
void jedzenie::przesunJedzenie() {
	p.set((rand() % 18) + 1, (rand() % 18) + 1);
}


jedzenie::~jedzenie()
{

}
