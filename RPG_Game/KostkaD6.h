#ifndef KostkaD6_H_INCLUDED
#define KostkaD6_H_INCLUDED
#include <random>

using namespace std;

class KostkaD6
{
public:
	KostkaD6();
	~KostkaD6();
	int Rzut(int nKostka);

private:
	uniform_int_distribution<int> d6 = uniform_int_distribution<int>(1, 6);
	mt19937 rng = mt19937(random_device{}());
};

#endif