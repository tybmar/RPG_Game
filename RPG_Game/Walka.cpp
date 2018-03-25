#include "Walka.h"



Walka::Walka()
{
}


Walka::~Walka()
{
}

void Walka::Starcie(Postac& f1, Postac& f2)
{
	
	auto* p1 = &f1;
	auto* p2 = &f2;
	if (p1->Inicjatywa() < p2->Inicjatywa())
	{
		swap(p1, p2);
	}
	p1->Atak(*p2);
	p2->Atak(*p1);
	
}


void Walka::AtakSpecjalny(Postac& f1, Postac& f2)
{
	auto* p1 = &f1;
	auto* p2 = &f2;
	if (p1->getDex() < p2->getDex())
	{
		swap(p1, p2);
	}
	p1->Specjal(*p2);
	//WezBronPrzegranego(*p1, *p2);
	p2->Specjal(*p1);
	//WezBronPrzegranego(*p2, *p1);
}