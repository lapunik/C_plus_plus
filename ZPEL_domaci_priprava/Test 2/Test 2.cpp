#include <iostream>
#include <string>

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

int nacti_hodnotu(std::string vyzva, int min, int max)
{
	int hodnota = 0;

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

double vypocet_taxy(double kilometry) 
{
	if (kilometry < 25) 
	{
		return kilometry * 24.0;
	}
	else if (kilometry < 50)
	{
		return kilometry * 21.0;
	}
	else if (kilometry < 75)
	{
		return kilometry * 17.0;
	}
	else
	{
		return kilometry * 12.0;
	}

}

double vypocet_ceny(int pocet_kusu)
{
	if (pocet_kusu < 25)
	{
		return pocet_kusu * 24.9;
	}
	else if (pocet_kusu < 50)
	{
		return pocet_kusu * 21.9;
	}
	else if (pocet_kusu < 75)
	{
		return pocet_kusu * 17.9;
	}
	else
	{
		return pocet_kusu * 12.9;
	}

}

void vypis_taxy(double cena_bez_nastupu) 
{
	std::cout << "Cena za ujete km: " << cena_bez_nastupu << "\n";
	std::cout << "Zakaznik zaplati: " << cena_bez_nastupu + 40.0 << "\n";
}

void vypis_ceny(double cena_bez_dopravy)
{
	std::cout << "Cena za soucastky: " << cena_bez_dopravy << "\n";
	std::cout << "Zakaznik zaplati: " << cena_bez_dopravy + 40.0 << "\n";
}

class Taxi 
{
public:
	double kilometry;
	double cena_bez_nastupu;

	Taxi(double k)
	{
		kilometry = k;
	}

	Taxi()
	{
	}

	void vypocet_taxy()
	{
		if (kilometry < 25)
		{
			cena_bez_nastupu = kilometry * 24.0;
		}
		else if (kilometry < 50)
		{
			cena_bez_nastupu = kilometry * 21.0;
		}
		else if (kilometry < 75)
		{
			cena_bez_nastupu = kilometry * 17.0;
		}
		else
		{
			cena_bez_nastupu = kilometry * 12.0;
		}

	}

	void vypis_taxy()
	{
		std::cout << "Cena za ujete km: " << cena_bez_nastupu << "\n";
		std::cout << "Zakaznik zaplati: " << cena_bez_nastupu + 40.0 << "\n";
	}

	void nastav_kilometry(double k) 
	{
		kilometry = k;
	}

};

class Nakup
{
public:
	int pocet_kusu;
	double cena_bez_dopravy;

	Nakup(int p)
	{
		pocet_kusu = p;
	}

	Nakup()
	{
	}

	void vypocet_ceny()
	{
		if (pocet_kusu < 25)
		{
			cena_bez_dopravy = pocet_kusu * 24.9;
		}
		else if (pocet_kusu < 50)
		{
			cena_bez_dopravy = pocet_kusu * 21.9;
		}
		else if (pocet_kusu < 75)
		{
			cena_bez_dopravy = pocet_kusu * 17.9;
		}
		else
		{
			cena_bez_dopravy = pocet_kusu * 12.9;
		}

	}

	void vypis_ceny()
	{
		std::cout << "Cena za soucastky: " << cena_bez_dopravy << "\n";
		std::cout << "Zakaznik zaplati: " << cena_bez_dopravy + 40.0 << "\n";
	}

	void nastav_pocet_kusu(int p)
	{
		pocet_kusu = p;
	}

};

int main()
{
	double kilometry = nacti_hodnotu("Zadej: ", 1.0, 1500.0);

	//double cena_bez_nastupu = vypocet_taxy(kilometry);

	//vypis_taxy(cena_bez_nastupu);

	Taxi t(kilometry);
	t.vypocet_taxy();
	t.vypis_taxy();

	//Taxi t2;
	//t2.nastav_kilometry(kilometry);
	//t2.vypocet_taxy();
	//t2.vypis_taxy();

	////////////////////////////////////////////////////////////

	//int pocet_kusu = nacti_hodnotu("Zadej: ", 1.0, 1500.0);

	////double cena_bez_nastupu = vypocet_taxy(kilometry);

	////vypis_taxy(cena_bez_nastupu);

	//Nakup n(pocet_kusu);
	//n.vypocet_ceny();
	//n.vypis_ceny();

	//Nakup n2;
	//n2.nastav_pocet_kusu(pocet_kusu);
	//n2.vypocet_ceny();
	//n2.vypis_ceny();

}