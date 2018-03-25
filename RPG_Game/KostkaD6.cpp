#include "KostkaD6.h"

int KostkaD6::Rzut(int nKostka)
{
	int total = 0;
	for (int n = 0; n < nKostka; n++)
	{
		total += d6(rng);
	}
	return total;
}

KostkaD6::KostkaD6()
{
}

KostkaD6::~KostkaD6()
{
}
