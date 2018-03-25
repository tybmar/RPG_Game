#include "Sztylet.h"



Sztylet::Sztylet()
	:Bron("Sztylet", 3) {}


Sztylet::~Sztylet()
{
	cout << "Sztylet zniszczony" << endl;
}

int Sztylet::KalkulacjaObrazen(const Atrybuty & attr, KostkaD6 & d) const
{
	return attr.str + d.Rzut(1);

}
