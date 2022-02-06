// Neco_jako_zapocet.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

double nacti_hodnotu(std::string vyzva, double min, double max)
{
	double hodnota = 0;

	std::cout << vyzva;
	std::cin >> hodnota;
	//std::cout << "\n";

	while ((std::cin.fail()) || (hodnota > max) || (hodnota < min))
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << vyzva;
		std::cin >> hodnota;
		//std::cout << "\n";
	}


	return hodnota;
}

void vypocet_rychlosti(double rychlosti[6]) 
{
	std::cout << rychlosti[0] << "   ";

	for (int i = 1; i < 6; i++)
	{
		rychlosti[i] = rychlosti[i - 1] * (19.0/20.0);
		std::cout << rychlosti[i] << "   ";
	}

	std::cout << "\n";
}

void prumer_a_vzdalenost(double rychlosti[6])
{
	double soucet = 0;

	for (int i = 0; i < 6; i++)
	{
		soucet += rychlosti[i];
	}

	std::cout << "Prumerna rychlost: " << soucet / 6.0 << " km/h\n";
	std::cout << "Ubehnuta vzdalenost: " << (soucet / 6.0)*1000 << " m\n";

}

//class Zavodnik
//{
//public:
//	double rychlosti[6];
//
//	Zavodnik()
//	{
//	}
//
//	Zavodnik(double rychlost)
//	{
//		rychlosti[0] = rychlost;
//	}
//
//	void vypocet_rychlosti()
//	{
//		std::cout << rychlosti[0] << "   ";
//
//		for (int i = 1; i < 6; i++)
//		{
//			rychlosti[i] = rychlosti[i - 1] * (19.0 / 20.0);
//			std::cout << rychlosti[i] << "   ";
//		}
//
//		std::cout << "\n";
//	}
//
//	void prumer_a_vzdalenost()
//	{
//		double soucet = 0;
//
//		for (int i = 0; i < 6; i++)
//		{
//			soucet += rychlosti[i];
//		}
//
//		std::cout << "Prumerna rychlost: " << soucet / 6.0 << " km/h\n";
//		std::cout << "Ubehnuta vzdalenost: " << (soucet / 6.0) * 1000 << " m\n";
//
//	}
//
//	void nastav_rychlost(double rychlost) 
//	{
//		rychlosti[0] = rychlost;
//	}
//
//};


int main()
{
	double rychlosti[6];

	rychlosti[0] = nacti_hodnotu("Zadej cislo od 15 do 25: ", 15, 25);


	std::cout << "Zavodnikova pocatecni rychlost je " << rychlosti[0] << " km/h\n";
	
	//vypocet_rychlosti(rychlosti);
	//prumer_a_vzdalenost(rychlosti);


	Zavodnik z(20);
	z.vypocet_rychlosti();
	z.prumer_a_vzdalenost();

	//Zavodnik z2;
	//z2.nastav_rychlost(15.5);
	//z2.vypocet_rychlosti();
	//z2.prumer_a_vzdalenost();



	 std::string slovo;

	if (true) 
	{
		slovo = "ahoj";
	}
	else 
	{
		slovo = "nashle";
	}


	std::cout << slovo;


}