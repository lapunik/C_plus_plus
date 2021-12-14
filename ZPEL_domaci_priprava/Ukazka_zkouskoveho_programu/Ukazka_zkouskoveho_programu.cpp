#include <iostream>

int nacti_hodnotu(std::string vyzva, int min, int max) 
{
	int hodnota = 0;

	std::cout << vyzva;
	std::cin >> hodnota;
	std::cout << "\n";

	while ((std::cin.fail()) || (hodnota > max) || (hodnota < min))
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << vyzva;
		std::cin >> hodnota;
		std::cout << "\n";
 	}


	return hodnota;
}

void pocty_knih(int police[20], int diference) 
{
	std::cout << police[0] << " ";

	for (int i = 1; i < 20; i++) 
	{
		police[i] = police[i - 1] + diference;
		std::cout << police[i] << " ";
	}

	std::cout << "\n";
}

void soucet_prumer(int police[20]) 
{
	double soucet = 0;
	
	for (int i = 0; i < 20; i++) 
	{
		soucet += police[i];
	}

	std::cout << "Soucet: " << soucet << "\n";
	std::cout << "Prumer: " << soucet/20 << "\n";
	
}

class Knihy
{
public:
	int police[20] = {};
	int diference;
	void pocty_knih() 
	{
		std::cout << police[0] << " ";

		for (int i = 1; i < 20; i++)
		{
			police[i] = police[i - 1] + diference;
			std::cout << police[i] << " ";
		}

		std::cout << "\n";
	}
	void soucet_prumer() 
	{
		double soucet = 0;

		for (int i = 0; i < 20; i++)
		{
			soucet += police[i];
		}

		std::cout << "Soucet: " << soucet << "\n";
		std::cout << "Prumer: " << soucet / 20 << "\n";
	}
	void nastav_diferenci(int d) 
	{
		diference = d;
	}
	void nastav_prvni_polici(int pocet) 
	{
		police[0] = pocet;
	}

};

int main()
{
	/*
	std::cout << nacti_hodnotu("Zadej: ", 3, 12) << "\n";

	int police[20] = {};
	police[0] = 1;
	pocty_knih(police, 2);

	soucet_prumer(police);
	//*/

	int prvni_police = nacti_hodnotu("Zadej cislo od 1 do 9: ", 1, 9);
	int diference = nacti_hodnotu("Zadej cislo od 2 do 5: ", 2, 5);

	std::cout << diference << "\n";
	std::cout << prvni_police << "\n";

	std::cout << "Pocet knih v 1. polici: " << prvni_police << ", diference posloupnosti: " << diference << "\n";

	Knihy knihy;
	knihy.nastav_prvni_polici(prvni_police);
	knihy.nastav_diferenci(diference);

	knihy.pocty_knih();
	knihy.soucet_prumer();
}
