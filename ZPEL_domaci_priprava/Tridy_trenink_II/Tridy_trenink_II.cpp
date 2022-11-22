#include <iostream>

#define STRED_HRACI_PLOCHY 10
#define SIRKA_BLOKU 10
#define VYSKA_BLOKU 10

class Nadoba
{
public:

	Nadoba()
	{
		Zmen_velikost(2,1);
	}

	Nadoba(double vyska, double prumer)
	{
		Zmen_velikost(vyska, prumer);
	}

	void Zmen_velikost(double vyska, double prumer)
	{
		objem = 0;
		prumer_zakladny = prumer;
		this->vyska = vyska;
		max_objem = 3.14 * vyska * prumer_zakladny * prumer_zakladny * 1000; // [l]
	}

	bool Dolej(double litry)
	{
		if (max_objem >= (objem + litry))
		{
			objem += litry;
			return true;
		}
		else 
		{
			return false;
		}
	}

	bool Vypust(double litry)
	{
		if (litry <= objem)
		{
			objem = objem-litry;
			return true;
		}
		else
		{
			return false;
		}
	}

	void Stav_litry() 
	{
		std::cout << "Nadoba je naplnena " << objem << "/" << max_objem << "\n";
	}

	void Stav_procenta()
	{
		std::cout << "Nadoba je naplnena z " << (objem/max_objem)*100 << "%\n";
	}

private:
	double prumer_zakladny = 1; // [m]
	double vyska = 1; // [m]
	double max_objem = 3.14 * vyska * prumer_zakladny * prumer_zakladny * 1000; // [l]  
	double objem = 0;
};


int main()
{

	Nadoba nadoba;

	nadoba.Stav_litry();
	nadoba.Stav_procenta();

	nadoba.Dolej(5000);

	nadoba.Stav_litry();
	nadoba.Stav_procenta();

	nadoba.Vypust(1500);

	nadoba.Stav_litry();
	nadoba.Stav_procenta();

}
