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
#include <conio.h>
#include <algorithm>



int main()
{
	//vector<unique_ptr<Postac>> t1;
	//t1.push_back(make_unique<Bohater>("", make_unique<Miecz>()));
	//
	//

	//vector<unique_ptr<Postac>> t2;
	//t2.push_back(make_unique<BadGuys>("Chong", make_unique<Miecz>()));
	//t2.push_back(make_unique<BadGuys>("Scumbag Steve", make_unique<Sztylet>()));

	vector<Postac*>t1 = {
		new Bohater("","",new Miecz),
		new Bohater("","",new Miecz),
	};
	vector<Postac*>t2 = {
		new BadGuys("","Julek",new Korbacz),
		new BadGuys("","Romek",new Sztylet),
	};


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
			cout << "------------------------------------" << std::endl;
		}
		cout << "=====================================" << std::endl;

		for (size_t i = 0; i < t1.size(); i++)
		{
			t1[i]->Regen();
			t2[i]->Regen();
		}
		cout << "=====================================" << std::endl;

		cout << "Nacisnij aby kontynuowac";
		while (!_kbhit());
		_getch();
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

	while (!_kbhit());
	return 0;

}