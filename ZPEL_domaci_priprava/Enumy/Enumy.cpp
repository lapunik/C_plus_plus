#include <iostream>

using namespace std;
//*
enum Rasa
{
	clovek,
	elf,
	trpaslik,
	skret,
	hobit,

};
//*/
int main()
{
	//*
	int pocet = 3;

	switch (pocet)
	{
	case 1:
		cout << "Pocet je jedna\n";
		break;
	case 2:
		cout << "Pocet je dva\n";
		break;
	case 3:
		cout << "Pocet je tri\n";
		break;
	default:
		break;
	}
	//*/

	/*
	Rasa r = trpaslik;

	switch (r)
	{
	case clovek:
		cout << "Ahoj clovece";
		break;
	case elf:
		cout << "Ahoj elfe";
		break;
	case trpaslik:
		cout << "Ahoj trpasliku";
		break;
	case skret:
		cout << "Ahoj skrete";
		break;
	case hobit:
		cout << "Ahoj hobite";
		break;
	default:
		break;
	}
	//*/
	
	/*
	Rasa r = trpaslik;

	if(r == 2)
	{
		cout << "Trpaslik";
	}
	//*/
}
