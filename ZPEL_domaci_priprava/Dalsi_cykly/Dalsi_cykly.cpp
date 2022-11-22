#include <iostream>
#include<conio.h>

int main()
{
	// Přerušení cyklů:
	/*
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

	
	
	// DO WHILE vs WHILE   KROKOVAT!!!!

	int cislo = 1;

	std::cout << "Nejprve normalni while: \n";

	while (cislo <= 0) 
	{
		std::cout << "Zadej kladnou hodnotu: ";
		std::cin >> cislo;
	}

	cislo = 1;

	std::cout << "Nyni do while: \n";

	do 
	{
		std::cout << "Zadej kladnou hodnotu: ";
		std::cin >> cislo;

	} while (cislo <= 0);

	*/

	// UDĚLAT SWITCH POMOCÍ IF (NEBO, A ZÁROVEŇ) 	

	int cislo = 0;

	std::cout << "Zadej cislo: ";

	std::cin >> cislo;

	switch (cislo)
	{
	case 0:
		std::cout << "\nHodnota byla nula.\n";
		break;
	case 1:
		std::cout << "\nHodnota byla jedna.\n";
		break;
	case 2:
		std::cout << "\nHodnota byla dva.\n";
		break;
	default:
		std::cout << "\nHodnota nebyla nula, jedna, ani dva.\n";
		break;
	}


	/*
	char znak;

	while (true)
	{
		if (_kbhit()) {

			znak = _getch();

			if (int(znak) == 27) // Escape
			{
				break;
			}

			//cout << "Znak: " << znak << " (ASCII:" << (int)znak << ")\n";

		}

		//cout << "nic\n";
		//Sleep(1000);
		//cout << "\033[2J\033[1;1H"; smazani console	
	}


	// Faktorial

	int hodnota = 1;
	int faktorial = 1;

	std::cout << "Zadej cislo: ";

	std::cin >> hodnota;

	for (int i = 1; i <= hodnota; i++)
	{
		faktorial *= i;
	}

	std::cout << "Faktorial cisla " << hodnota << " je " << faktorial;

	*/
}