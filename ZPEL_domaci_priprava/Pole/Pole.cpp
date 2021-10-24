#include <iostream>

using namespace std;

int main()
{
	//*

	const int velikost_pole = 10;

	// cin >> velikost_pole; → v projektu Dynamicke_pole

	int *pole = new int[velikost_pole]; // nic jako datový typ pole neexistuje v C++, existuje jenom ukazatel na adresu, kde pole začíná

	pole[0] = 15;

	cout << "Hodnota v poli na miste 0 je: " << pole[0] << "\n";

	cout << "Hodnota v poli na miste 2 je: " << pole[2] << "\n"; // nějaká blbost!! pozor na to

	pole[2] = 4;

	cout << "Hodnota v poli na miste 2 je: " << pole[2] << "\n";

	for (int i = 0; i < velikost_pole; i++)
	{
		pole[i] = i;
	}

	cout << "Kompletni pole:\n";

	for (int i = 0; i < velikost_pole; i++)
	{
		cout << pole[i] << "\n";
	}

	//*/


	string slovo_string = "Ahoj";

	cout << "Slovo je: " << slovo_string << "\n";

	cout << "Pismeno na indexu 2 je: " << slovo_string[2] << "\n";

	/// //////////////////////////////////////////////////////////////////////////////

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

	cout << "Pismeno na indexu 2 je: " << slovo_pole_char[2] << "\n";
}