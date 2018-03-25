#include "BadGuys.h"


BadGuys::BadGuys(const string& rasa, const string& imie, Bron* pBron=nullptr)
	:Postac(rasa, imie,5,5,5,pBron)
{
	WylosujCharakterystyki();
	cout << getRasa()<<" "<<GetImie() << " wchodzi na arene." << endl;
}


BadGuys::~BadGuys()
{
	cout << imie << " zostal zniszczony" << endl;
}

void BadGuys::Atak()
{
}

void BadGuys::WylosujCharakterystyki()
{
	uniform_int_distribution<int> dist = uniform_int_distribution<int>(1, 100);
	mt19937 rng = mt19937(random_device{}());
	setStr(dist(rng));
	setDex(dist(rng));
	setHP(dist(rng));
}

void BadGuys::Specjal(Postac & other)
{
	if (CzyZyje() && other.CzyZyje())
	{
		if (Rzut() > 2)
		{
			cout << GetImie() << " zadaje " << other.GetImie() << " krytyczne obrazenia!" << endl;
			ZadanieObrazen(other, Rzut(3) + 20);
		}
	}
}