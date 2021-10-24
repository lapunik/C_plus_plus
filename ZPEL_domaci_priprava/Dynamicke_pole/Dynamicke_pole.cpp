#include <iostream>

using namespace std;

int* Vynasob_pole_dvojkou(int* pole, int velikost_pole) 
{
	int *nove_pole = new int[velikost_pole];

	for (int i = 0; i < velikost_pole; i++)
	{
		
		nove_pole[i] = pole[i] * 2;

	}

	return nove_pole;

}

int Maximum(int* pole, int velikost_pole) 
{
	int max = pole[0];

	for (int i = 1; i < velikost_pole; i++)
	{
		if (pole[i] > max) 
		{
			max = pole[i];
		}
	}

	return max;
}

int main()
{

	//*

	int velikost_pole;
	cout << "Zadej velikost pole: ";
	cin >> velikost_pole;


	int* pole = new int[velikost_pole];

	for (int i = 0; i < velikost_pole; i++)
	{
		pole[i] = i;
	}

	for (int i = 0; i < velikost_pole; i++)
	{
		cout << pole[i] << "\n";
	}

	delete[] pole;
	pole = NULL;

	//*/

	/*

	int *pole = new int[4];

	pole[0] = 10;
	pole[1] = 6;
	pole[2] = 13;
	pole[3] = 2;

	//cout << Maximum(pole,4);

	int* pole_2 = Vynasob_pole_dvojkou(pole,4);

	for (int i = 0; i < 4; i++)
	{

		cout << pole_2[i] << "\n";

	}
	
	//*/
}