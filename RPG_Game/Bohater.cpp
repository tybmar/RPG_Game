#include "Bohater.h"




Bohater::Bohater(const string& rasa, const string& imie, Bron* pBron=nullptr)
	: Postac(rasa,imie,5,5,5,pBron)
{
	StworzPostac();
	cout << endl;
	cout << GetImie() << " wchodzi na arene." << endl;
}



Bohater::~Bohater()
{
	cout << imie << " zostal zniszczony" << endl;
}


void Bohater::WyborImieniaRasy()
{
	cout << "Wprowadz imie bohatera " << endl;
	cin >> imie;
	setName(imie);
	TworzenieBohatera:
	cout << "Wybierz rase " << endl;
	cout << "1. Czlowiek" << endl;
	cout << "2. Ork" << endl;
	cout << "3. Elf" << endl;
	cout << "4. Krasnolud" << endl;
	cin >> wyborRasy;


	switch (wyborRasy)
	{
	case 1:
		rasa= "Czlowiekiem";
		break;
	case 2:
		rasa = "Orkiem";
		break;
	case 3:
		rasa = "Elfem";
		break;
	case 4:
		rasa = "Krasnoludem";
		break;

	default:
	{
		cout << "Nie ma takiej opcji! Ponownie wybierz rase" << endl;
		goto TworzenieBohatera;
	}
	}
	
	setRace(rasa);

}


void Bohater::WylosujCharakterystyki()
{
	uniform_int_distribution<int> dist = uniform_int_distribution<int>(1, 100);
	mt19937 rng = mt19937(random_device{}());
	setStr(dist(rng));
	setDex(dist(rng));
	setHP(dist(rng));
}

void Bohater::PrintPostac() 
{
	cout << "Nazywasz sie " << GetImie() << endl;
	cout << "Jestes " << getRasa() << endl;
	cout << "Masz " << getStr() << " sily, " << getDex() <<
		" zrecznosci, " << getHP() << " wytrzymalosci.";
}

void Bohater::StworzPostac()
{
	WyborImieniaRasy();
	WylosujCharakterystyki();
	PrintPostac();
}

void Bohater::Atak()
{
}

void Bohater::Specjal(Postac & other)
{
	if (CzyZyje() && other.CzyZyje())
	{
		if (Rzut() > 4)
		{
			cout << GetImie() << " zadaje " << other.GetImie() << " krytyczne obrazenia!" << endl;
			ZadanieObrazen(other, Rzut(2) + 20);
		}
	}
}
