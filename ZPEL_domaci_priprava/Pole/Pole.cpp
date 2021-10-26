#include <iostream>

using namespace std;

//void Zmen_pole(int *pole)
void Zmen_pole(int pole[]) 
{
	pole[0] = 999;
}

int main()
{
	//*

	const int velikost_pole = 4;

	// cin >> velikost_pole; → v projektu Dynamicke_pole

	// int *pole = new int[velikost_pole]; // nic jako datový typ pole neexistuje v C++, existuje jenom ukazatel na adresu, kde pole začíná

	int pole[velikost_pole];

	pole[0] = 5;
	pole[1] = 7;
	pole[2] = 10;
	pole[3] = 3;

	cout << "Pole:\n";

	for (int i = 0; i < velikost_pole; i++)
	{
		cout << pole[i] << "\n";
	}

	Zmen_pole(pole); // stále se jedná o poiter!

	cout << "\nZmenene pole:\n";

	for (int i = 0; i < velikost_pole; i++)
	{
		cout << pole[i] << "\n";
	}	

	//*/

	/////////////////////////////////////////////////////////////////////////////////

	string slovo_string = "Ahoj";

	cout << "\nSlovo je: " << slovo_string << "\n";

	cout << "Pismeno na indexu 2 je: " << slovo_string[2] << "\n";

	char* slovo_pole_char = new char[4];

	slovo_pole_char[0] = 'A';
	slovo_pole_char[1] = 'h';
	slovo_pole_char[2] = 'o';
	slovo_pole_char[3] = 'j';

	cout << "Slovo je: ";

	for (int i = 0; i < 4; i++) 
	{
		cout << slovo_pole_char[i];
	}
	
	cout << "\n";

	cout << "Pismeno na indexu 2 je: " << slovo_pole_char[2] << "\n\n";

	///////////////////////////////////////////////////////////////////////////////////////

	// 1 2 3
	// 4 5 6
	// 7 8 9

	//int dvourozmerne_pole[3][3];

	int** dvourozmerne_pole = new int*[3];

	for (int i = 0; i < 3; i++) 
	{
		dvourozmerne_pole[i] = new int[3];
	}

	for (int j = 0 ; j < 3; j++) 
	{
		for (int i = 0; i < 3; i++)
		{
			dvourozmerne_pole[i][j] = ((3 * j) + (i + 1));
		}
	}

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << dvourozmerne_pole[i][j];
		}
		cout << "\n";
	}


}