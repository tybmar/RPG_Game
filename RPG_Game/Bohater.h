#ifndef Bohater_H_INCLUDED
#define Bohater_H_INCLUDED

#include "Postac.h"


class Bohater :
	public Postac
{
private:
	string rasa,imie;
	int wyborRasy;
public:
	Bohater(const string& rasa, const string& imie, Bron* pBron);

	~Bohater();

	//Functions
	void WyborImieniaRasy();
	void WylosujCharakterystyki();
	void PrintPostac();
	void StworzPostac();
	void Specjal(Postac& other) override;
	void Atak();
	
	

};

#endif