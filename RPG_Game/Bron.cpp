#include "Bron.h"



Bron::Bron(const string& name, int tier)
	:
	name(name),
	tier(tier)
{}


Bron::~Bron()
{
}

string& Bron::GetRodzaj() { return name; }
int Bron::GetTier() const { return tier; }
