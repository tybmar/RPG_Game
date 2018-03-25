#ifndef PRZEDMIOTY_H_INCLUDED
#define PRZEDMIOTY_H_INCLUDED
#include <string>
#include "KostkaD6.h"
#include "Atrybuty.h"

using namespace std;

class Przedmioty
{
	public:

		//Constructor
		Przedmioty(const string& name, int tier);

		//Getters
		string& GetRodzaj(){return name;}
		int GetTier() const{return tier;}

		//Functions
		virtual int WypicieMikstury(const Atrybuty& attr, KostkaD6& d) const = 0;

		//Destructor
		virtual ~Przedmioty() = default;

	private:
		string name;
		int tier;
	
};

#endif
