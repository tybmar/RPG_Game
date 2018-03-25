#include "Postac.h"


Postac::Postac(string rasa, string imie, int str, int dex, int hitpoints, Bron* pBron = nullptr)
	:
	rasa(rasa),
	imie(imie),
	attr({ str, dex, hitpoints }),
	pBron(pBron)
{
}


Postac::~Postac()
{
	delete pBron;
	cout << "Postac zniknela z powierzchni Ziemi" << endl;
}

void Postac::Atak(Postac &other)
{
	if (CzyZyje() && other.CzyZyje())
	{
		cout << imie << " wyprowadza atak " << other.GetImie() << " "<<pBron->GetRodzaj()<<endl;
		ZadanieObrazen(other, pBron->KalkulacjaObrazen(attr, d));
	}
}

void Postac::ZadanieObrazen(Postac & cel, int obrazenia) const
{
		cel.attr.hp -= obrazenia;
		cout << cel.imie << " dostaje " << obrazenia << " obrazen." << endl;
		if (!cel.CzyZyje())
		{
			cout << "Zycie uchodzi z " << cel.imie << "jak powietrze z balonika. Umiera." << endl;
		}
}

int Postac::Inicjatywa() const
{
	return attr.dex + Rzut(2);
}

void Postac::DajBron(Bron* pNowaBron)
{
	delete pBron;
	pBron = pNowaBron;
}

Bron* Postac::ZabierzBron()
{
	auto pB = pBron;
	pBron = nullptr;
	return pB;
}

bool Postac::CzyZyje()const
{
	return attr.hp>0;
}

void Postac::Regen()
{
	if (CzyZyje())
	{
		const int regen = Rzut();
		cout << imie << " odzyskuje " << regen << " hitpoints." <<endl;
		attr.hp += regen;
	}
}

void Postac::Zmeczenie()
{
	if (CzyZyje())
	{
		const int stamina = Rzut();
		cout << GetImie() << " opada z sil!" <<endl;
		attr.dex-=stamina;
	}
}


void Postac::setRace(string r)
{
	rasa = r;
}
void Postac::setName(string n)
{
	imie = n;
}

void Postac::setStr(int s)
{
	attr.str = s;
}
void Postac::setDex(int d)
{
	attr.dex=d;
}
void Postac::setHP(int h)
{
	attr.hp = h;
}

int Postac::Rzut(int nKostka) const
{
	return d.Rzut(nKostka);
}