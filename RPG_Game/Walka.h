#ifndef Walka_H_INCLUDED
#define Walka_H_INCLUDED
#include "Postac.h"

class Walka
{
public:
	Walka();
	~Walka();

	static void Starcie(Postac& f1, Postac& f2);
	static void AtakSpecjalny(Postac& f1, Postac& f2);

};

#endif