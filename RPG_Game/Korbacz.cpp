#include "Korbacz.h"



Korbacz::Korbacz()
	:Bron("Korbacz", 2) {}


Korbacz::~Korbacz()
{
	cout << "Korbacz zniszczony" << endl;
}

int Korbacz::KalkulacjaObrazen(const Atrybuty & attr, KostkaD6 & d) const
{
	return attr.dex - d.Rzut(3);

}
