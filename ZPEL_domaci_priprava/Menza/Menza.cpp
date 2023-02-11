#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h> 
#include <limits>
#include <ios>

int vyber(std::string vyzva, int max) 
{

	int moznost;
	std::cout << vyzva;
	std::cin >> moznost;

	while ((std::cin.fail()) || (moznost > max) || (moznost < 1))
	{
		std::cout << "\n" << vyzva;
		std::cin.clear();
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		std::cin >> moznost;
	}

	std::cout << "\n";

	return moznost;
}

void pridat_osobu(std::vector<std::string> &seznam)
{
	std::string jmeno;
	std::cout << "Zadej jmeno nove osoby: ";
	std::cin >> jmeno;
	std::cout << "\n";

	seznam.push_back(jmeno);
}

void smazat_osobu(std::vector<std::string>& seznam)
{
	if (seznam.size() < 1)
	{
		std::cout << "Seznam je prazdny!\n\n";
	}
	else
	{
		std::cout << "Osoba " << seznam.at(seznam.size() - 1) << " byla smazana ze seznamu.\n\n";

		seznam.pop_back();
	}
}
void zobraz_seznam(std::vector<std::string>& seznam)
{
	std::cout << "Seznam osob:\n\n";

	if (seznam.size() == 0)
	{
		std::cout << "Seznam je prazdny!";
	}
	else
	{
		for (int i = 0; i < seznam.size(); i++)
		{
			std::cout << i+1 << ". " << seznam.at(i) << "\n";
		}
	}

	std::cout << "\n\n";
}

int main()
{
	std::vector<std::string> seznam;

	while (true)
	{
		std::cout << "System menzy:\n\n";

		std::cout << "1. Seznam osob\n2. Pridat osobu\n3. Odstranit osobu\n4. Ukoncit\n\n";

		int moznost = vyber("Vyber jednu z moznosti: ", 4);

		system("CLS");

		switch (moznost)
		{
		case 1:
			zobraz_seznam(seznam);
			break;
		case 2:
			pridat_osobu(seznam);
			break;
		case 3:
			smazat_osobu(seznam);
			break;
		case 4:
			std::cout << "Konec.\n";
			return 0;
		}

		std::cout << "Pokracuj stiskem ENTER.";
		std::cin.clear();
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		while (std::cin.get() != '\n');

		system("CLS");

	}

}