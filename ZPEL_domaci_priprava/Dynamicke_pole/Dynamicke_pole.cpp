﻿#include <iostream>

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

int najdi_indexy_vyskytu_hodnoty(int* pole, int velikost_pole, int hodnota) 
{
	int* cetnost_temp = new int[velikost_pole];
	int counter = 0;

	for (int i = 0; i < velikost_pole; i++) 
	{
		if (pole[i] == hodnota) 
		{
			cetnost_temp[counter] = i;
			counter++;

		}
	}

	for (int i = 0;i < counter;i++) 
	{
		pole[i] = cetnost_temp[i];
	}

	return counter;
}

int main()
{

	/*

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

	/*

	int* pole = new int[13];

	pole[0] = 1;
	pole[1] = 2;
	pole[2] = 3;
	pole[3] = 5;
	pole[4] = 9;
	pole[5] = 1;
	pole[6] = 4;
	pole[7] = 7;
	pole[8] = 8;
	pole[9] = 1;
	pole[10] = 8;
	pole[11] = 2;
	pole[12] = 3;



	int pocet = najdi_indexy_vyskytu_hodnoty(pole, 13, 1);

	for (int i = 0; i < pocet; i++)
	{

		cout << pole[i] << "\n";

	}

	*//
}