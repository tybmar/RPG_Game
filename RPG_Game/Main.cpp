#include <iostream>
#include "Bohater.h"
#include "Przedmioty.h"
#include "Bron.h"
#include "Korbacz.h"
#include "Miecz.h"
#include "Sztylet.h"
#include "BadGuys.h"
#include "Walka.h"
#include <vector>
#include <algorithm>



int main()
{

	vector<Postac*>t1 = {
		new Bohater("","",new Miecz),
		new Bohater("","",new Miecz),
	};
	vector<Postac*>t2 = {
		new BadGuys("","Julek",new Korbacz),
		new BadGuys("","Romek",new Sztylet),
	};

	cout << "Bohater: " << t1[0]->GetImie() << " hitpoints: " << t1[0]->getHP() << endl;
	cout << "Bohater: " << t1[1]->GetImie() << " hitpoints: " << t1[1]->getHP() << endl;

	cin.get();
	cin.get();

	const auto alive_pred = [](Postac* pf) { return pf->CzyZyje(); };
	while (
		any_of(t1.begin(), t1.end(), alive_pred) &&
		any_of(t2.begin(), t2.end(), alive_pred))
	{
		random_shuffle(t1.begin(), t1.end());
		partition(t1.begin(), t1.end(), alive_pred);
		random_shuffle(t2.begin(), t2.end());
		partition(t2.begin(), t2.end(), alive_pred);

		for (size_t i = 0; i < t1.size(); i++)
		{
			Walka::Starcie(*t1[i], *t2[i]);
			Walka::AtakSpecjalny(*t1[i], *t2[i]);
			cout << "------------------------------------" << endl;
		}
		cout << "=====================================" << endl;

		for (size_t i = 0; i < t1.size(); i++)
		{
			t1[i]->Regen();
			t2[i]->Regen();
		}
		cout << "=====================================" << endl;

		cout << "Nacisnij aby kontynuowac";
		cin.get();
		
		cout << endl << endl;
	}

	if (any_of(t1.begin(), t1.end(), alive_pred))
	{
		cout << "Twoja paczka wygrala!" << endl;
	}
	else
	{
		cout << "Niestety przeciwnik okazal sie za mocny, przegrywasz." << endl;
	}

	for (size_t i = 0; i < t1.size(); i++)
	{
		delete t1[i];
		delete t2[i];
	}

	cin.get();
	return 0;

}