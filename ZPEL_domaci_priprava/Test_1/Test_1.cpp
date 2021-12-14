// Pobyt_v_zahranici, Prevod casu_v_sekundach, Udrzba_stroje

#include <iostream>
#include <string>

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

void prevod_casu(int cas[5], int sekundy)
{
	for (int i = 0; i < 5; i++) 
	{
		cas[i] = 0;
	}
	
	while(sekundy >= 604800) // větší než jeden týden
	{
		sekundy -= 604800;
		++cas[0];
	}
	while (sekundy >= 86400) // větší než jeden den
	{
		sekundy -= 86400;
		++cas[1];
	}
	while (sekundy >= 3600) // větší než jedna hodina
	{
		sekundy -= 3600;
		++cas[2];
	}
	while (sekundy >= 60) // větší než jedna minuta
	{
		sekundy -= 60;
		++cas[3];
	}
	cas[4] = sekundy;

}

void vypis_casu(int cas[5], int sekundy) 
{
	std::cout << "Byl zadan cas: " << sekundy << "\n";

	if (cas[0] > 0) 
	{
		std::cout << "tydnu: " << cas[0] << "\n";
	}
	if (cas[1] > 0)
	{
		std::cout << "dnu: " << cas[1] << "\n";
	}
	if (cas[2] > 0)
	{
		std::cout << "hodin: " << cas[2] << "\n";
	}
	if (cas[3] > 0)
	{
		std::cout << "minut: " << cas[3] << "\n";
	}
	if (cas[4] > 0)
	{
		std::cout << "sekund: " << cas[4] << "\n";
	}
	
}

class Cas
{
private:

	int cas[5];
	int sekundy = 0;

public:
	
	Cas() 
	{
	}

	Cas(int s)
	{
		sekundy = s;
	}

	void prevod_casu()
	{
		int s = sekundy;

		for (int i = 0; i < 5; i++)
		{
			cas[i] = 0;
		}

		while (sekundy >= 604800) // větší než jeden týden
		{
			sekundy -= 604800;
			++cas[0];
		}
		while (sekundy >= 86400) // větší než jeden den
		{
			sekundy -= 86400;
			++cas[1];
		}
		while (sekundy >= 3600) // větší než jedna hodina
		{
			sekundy -= 3600;
			++cas[2];
		}
		while (sekundy >= 60) // větší než jedna minuta
		{
			sekundy -= 60;
			++cas[3];
		}
		cas[4] = sekundy;
		sekundy = s;

	}

	void vypis_casu()
	{
		std::cout << "Byl zadan cas: " << sekundy << "\n";

		if (cas[0] > 0)
		{
			std::cout << "tydnu: " << cas[0] << "\n";
		}
		if (cas[1] > 0)
		{
			std::cout << "dnu: " << cas[1] << "\n";
		}
		if (cas[2] > 0)
		{
			std::cout << "hodin: " << cas[2] << "\n";
		}
		if (cas[3] > 0)
		{
			std::cout << "minut: " << cas[3] << "\n";
		}
		if (cas[4] > 0)
		{
			std::cout << "sekund: " << cas[4] << "\n";
		}

	}

	void nastav_sekundy(int s) 
	{
		sekundy = s;
	}
};

int main()
{
	//int sekundy = nacti_hodnotu("Zadej cislo od 300 do 6000000: ", 300, 6000000);
	//int cas[5];
	//prevod_casu(cas, sekundy);
	////for (int i = 0; i < 5; i++)
	////{
	////	std::cout << cas[i] << "  ";
	////}
	//vypis_casu(cas, sekundy);

	//Cas cas(3661);
	//cas.prevod_casu();
	//cas.vypis_casu();

	//Cas cas;
	//cas.nastav_sekundy(3661);
	//cas.prevod_casu();
	//cas.vypis_casu();

	Cas cas(nacti_hodnotu("Zadej cislo od 300 do 6000000: ", 300, 6000000));
	cas.prevod_casu();
	cas.vypis_casu();

}
