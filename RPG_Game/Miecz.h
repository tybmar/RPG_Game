#ifndef Miecz_H_INCLUDED
#define Miecz_H_INCLUDED

#include "Bron.h"

class Miecz :
	public Bron
{
public:
	Miecz();
	~Miecz();
	//Functions
	int KalkulacjaObrazen(const Atrybuty& attr, KostkaD6& d) const;

};

#endif