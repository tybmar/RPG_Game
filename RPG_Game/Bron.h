#ifndef BRON_H_INCLUDED
#define BRON_H_INCLUDED

#include <iostream>
#include <string>
#include "KostkaD6.h"
#include "Atrybuty.h"

using namespace std;

class Bron 
{
public:
	//Constructor
	Bron(const string& name, int tier);
	//Getters
	string& GetRodzaj()		;
	int GetTier() const;
		
	//Functions
	virtual int KalkulacjaObrazen(const Atrybuty& attr, KostkaD6& d) const = 0;

	//Destructor
	virtual ~Bron();

private:
	string name;
	int tier;
};

#endif

