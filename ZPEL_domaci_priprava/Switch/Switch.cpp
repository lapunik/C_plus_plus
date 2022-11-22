#include <iostream>

int main()
{
	int cislo = 0;

	std::cout << "Zadej cislo: ";
	std::cin >> cislo;

	// KROKOVAT, ODSTRANIT ELSE OF IFŮ, ODSTRANIT BREAKY ZE SWITCHE

	if (cislo == 0) 
	{
		std::cout << "\nHodnota byla nula.\n";
	}
	else if(cislo == 1)
	{
		std::cout << "\nHodnota byla jedna\n";
	}
	else if (cislo == 2)
	{
		std::cout << "\nHodnota byla jedna\n";
	}
	else
	{
		std::cout << "\nHodnota nebyla nula, jedna ani dva\n";
	}

	//std::cout << "Zadej cislo: ";
	//std::cin >> cislo;


	//switch (cislo)
	//{
	//case 0:
	//	std::cout << "\nHodnota byla nula.\n";
	//	break;
	//case 1:
	//	std::cout << "\nHodnota byla jedna.\n";
	//	break;
	//case 2:
	//	std::cout << "\nHodnota byla dva.\n";
	//	break;
	//default:
	//	std::cout << "\nHodnota nebyla nula, jedna, ani dva.\n";
	//	break;
	//}
	return 0;
}