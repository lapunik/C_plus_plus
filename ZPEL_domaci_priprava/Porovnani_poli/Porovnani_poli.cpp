#include <iostream>

using namespace std;

bool* Porovnani_poli(int* pole1, int* pole2, int velikost)
{
	bool* pole_porovnani = new bool[velikost];

	for (int i = 0; i < velikost; i++)
	{
		pole_porovnani[i] = (pole1[i] == pole2[i]);
	}

	return pole_porovnani;
}

int main()
{
	int velikost = 5;

	int* teploty = new int[velikost];

	teploty[0] = 4;
	teploty[1] = 8;
	teploty[2] = 9;
	teploty[3] = 13;
	teploty[4] = 9;


	int* teploty2 = new int[velikost];

	teploty2[0] = 4;
	teploty2[1] = 6;
	teploty2[2] = 10;
	teploty2[3] = 13;
	teploty2[4] = 7;

	cout << "Porovnani, zda jsou teploty v prnim poli vetsi nez ve druhem : \n";

	bool* logicke_pole = Porovnani_poli(teploty, teploty2, velikost);

	for (int i = 0; i < velikost; i++)
	{
		cout << "Prvky na indexu " << i;
		if (logicke_pole[i]) 
		{
			cout << " se rovnaji.\n";
		}
		else 
		{
			cout << " se NErovnaji.\n";
		}
			
	}

}
