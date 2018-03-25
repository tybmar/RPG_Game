#ifndef Postac_H_INCLUDED
#define Postac_H_INCLUDED

using namespace std;
#include <string>
#include <iostream>
#include <random>
#include "KostkaD6.h"
#include "Atrybuty.h"
#include "Bron.h"

class Postac
{
private:
	mutable KostkaD6 d;
	Bron *pBron = nullptr;

protected:
	Atrybuty attr;
	string rasa, imie;
	int str, dex, hp;
	Postac(string rasa, string imie, int str, int dex, int hp, Bron* pBron);
	void ZadanieObrazen(Postac& target, int damage) const;
public:
	
	virtual ~Postac();

	//Functions
	int Rzut(int nKostka = 1) const;
	int Inicjatywa() const;
	virtual void Atak(Postac &other);
	bool CzyZyje()const;
	virtual void Regen();
	virtual void Zmeczenie();
	virtual void Specjal(Postac&) = 0;
	void DajBron(Bron* pNowaBron);
	Bron* ZabierzBron();




	//Accessors
	inline const string& getRasa() { return rasa; }
	inline const string& GetImie() { return imie; }
	inline const int& getStr() { return attr.str; }
	inline const int& getDex() { return attr.dex; }
	inline const int& getHP() { return attr.hp; }

	//Setters
	void setRace(string r);
	void setName(string n);
	void setStr(int s);
	void setDex(int d);
	void setHP(int h);

};
#endif
