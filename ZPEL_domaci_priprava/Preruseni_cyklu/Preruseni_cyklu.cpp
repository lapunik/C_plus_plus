#include <iostream>

int main()
{
	std::cout << "Zacatek programu \n";

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			//continue; // přeskoč současnou iteraci
			break; // přeskoč všechny zbylé iterace
			//return 0; // ukonči celou funkci (v našem případě funkce main)

		}

		std::cout << i << "\n";
	}

	std::cout << "Konec programu \n";
}