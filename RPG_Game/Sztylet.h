#ifndef Sztylet_H_INCLUDED
#define Sztylet_H_INCLUDED

#include "Bron.h"
class Sztylet :
	public Bron
{
public:
	Sztylet();
	~Sztylet();

	int KalkulacjaObrazen(const Atrybuty& attr, KostkaD6& d) const;

};

#endif