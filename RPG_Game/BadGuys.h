#ifndef BadGuys_H_INCLUDED
#define BadGuys_H_INCLUDED
#include "Postac.h"


class BadGuys :
	public Postac
{
public:
	BadGuys(const string& rasa, const string& imie, Bron* pBron);
	~BadGuys();

	//Functions
	void Specjal(Postac& other) override;
	void Atak();
	void WylosujCharakterystyki();
};

#endif