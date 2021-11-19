#include <iostream>

using namespace std;

int main()
{
	int vysledek = 0;
	int hodnota1 = 8;
	int hodnota2 = 5;
	double hodnota3 = 5.9;
	double vysledek_d = 0.0;

	vysledek = hodnota1 + hodnota2; // int = int + int
	vysledek = hodnota1 + hodnota3; // int = int + double (ořezává výsledek, nezaokrouhluje!)
	vysledek_d = hodnota1 + hodnota3; // double = int + double

	//cout << vysledek;

	char znak = 48; // znak z ASCII na místě 48

	cout << znak << "\n";
	cout << (int)znak << "\n"; // spíš nepoužívat

	cout << static_cast<int>(znak) << "\n";

}

