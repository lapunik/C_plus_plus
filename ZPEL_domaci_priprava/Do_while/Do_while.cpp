#include <iostream>

int main()
{
	int cislo = 1;

	std::cout << "Nejprve normalni while: \n";

	while (cislo <= 0)
	{
		std::cout << "Zadej kladnou hodnotu: ";
		std::cin >> cislo;
	}

	cislo = 1;

	std::cout << "\nNyni do while: \n";

	do
	{
		std::cout << "Zadej kladnou hodnotu: ";
		std::cin >> cislo;

	} while (cislo <= 0);
}
