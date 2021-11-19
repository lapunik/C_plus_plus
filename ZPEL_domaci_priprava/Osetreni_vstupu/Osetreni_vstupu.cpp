#include <iostream>

using namespace std;

int main()
{

	//*
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
