#include "HpPotka.h"



HpPotka::HpPotka()
	:Przedmioty("Mala mikstura leczenia", 1) {}


HpPotka::~HpPotka()
{
}

int HpPotka::WypicieMikstury(const Atrybuty& attr, KostkaD6& d) const
{
	return attr.str + d.Rzut(2);
}