#include "Miecz.h"



Miecz::Miecz()
	:Bron("Miecz", 1) {}


Miecz::~Miecz()
{
	cout << "Miecz zniszczony" << endl;
}

int Miecz::KalkulacjaObrazen(const Atrybuty& attr, KostkaD6& d) const
{
	return attr.str - d.Rzut(1);

}