#ifndef Korbacz_H_INCLUDED
#define Korbacz_H_INCLUDED
#include "Bron.h"
class Korbacz :
	public Bron
{
public:
	Korbacz();
	~Korbacz();

	int KalkulacjaObrazen(const Atrybuty& attr, KostkaD6& d) const;
};

#endif