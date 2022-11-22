#include <iostream>

int main()
{
	int hodnota = 1;
	int faktorial = 1;

	std::cout << "Zadej cislo: ";
	std::cin >> hodnota;

	for (int i = 1; i <= hodnota; i++)
	{
		faktorial *= i;
	}

	std::cout << "Faktorial cisla " << hodnota << " je " << faktorial;

}