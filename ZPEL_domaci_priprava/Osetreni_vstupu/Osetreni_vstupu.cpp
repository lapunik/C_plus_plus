#include <iostream>

using namespace std;

int soucin(int dolniMez, int horniMez)
{
	int soucin = 1;

	if ((dolniMez >= horniMez) || (dolniMez < 0))
	{
		return -1;
	}
	else
	{
		for (int i = dolniMez; i <= horniMez; i++)
		{
			soucin *= i;
		}
	}

	return soucin;

}

int main()
{

		int dolniMez = 2;
		int horniMez = 5;
		cout << soucin(dolniMez, horniMez);
		return 0;
	

	/*
	int a;

	cout << "Zadej cislo: ";

	cin >> a;

	if (cin.fail()) 
	{
		cout << "Zadana hodnota neni typu int";
	}
	//*/
	
	/*
	int a;

	cout << "Zadej cislo: ";

	cin >> a;
	while (cin.fail())
	{
		cout << "Zadana hodnota neni typu int!\nZadej cislo: ";
		cin.clear();
		cin.ignore(256,'\n');
		cin.ignore();
		cin >> a;
	}
	//*/


}
