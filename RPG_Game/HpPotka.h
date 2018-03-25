#ifndef HpPotka_H_INCLUDED
#define HpPotka_H_INCLUDED

#include "Przedmioty.h"
class HpPotka :
	public Przedmioty
{
public:
	HpPotka();
	~HpPotka();

	virtual int WypicieMikstury(const Atrybuty& attr, KostkaD6& d) const;

};

#endif
