#include "Postava.h"
#include <random>

std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator
std::uniform_int_distribution<> distr(0, 10); // define the range

Postava::Postava(std::string jmeno1, std::string rasa1)
{
	jmeno = jmeno1;
	rasa = rasa1;
}

void Postava::Predstav_se()
{
	std::cout << "Ahoj, ja jsem " << jmeno << " a jsem " << rasa << "\n";
}

void Postava::Ukaz_pocet_zivotu()
{
	if (pocet_zivotu <= 0) 
	{
		std::cout << jmeno << " je mrtvy \n";
	}
	else 
	{
		std::cout << jmeno << " ma " << pocet_zivotu << "/" << max_pocet_zivotu << " zivotu\n";
	}
}

void Postava::Utok(Postava &oponent)
{

	int poskozeni = zbran.poskozeni + distr(gen);

	std::cout << jmeno << " pusobi poskozeni za " << poskozeni << " bodu postave " << oponent.jmeno << "\n";

	//oponent.pocet_zivotu -= poskozeni;

	oponent.Obrana(poskozeni);
}

void Postava::Obrana(int poskozeni) 
{
	int ztrata_zivotu = 0;

	int durabilita = zbroj.durabilita + distr(gen);

	if (poskozeni > durabilita)
	{
		ztrata_zivotu = poskozeni - durabilita;
	}

	pocet_zivotu -= ztrata_zivotu;

	std::cout << jmeno << " prijma poskozeni za " << ztrata_zivotu << " bodu" << "\n";

	if (pocet_zivotu <= 0) 
	{
		pocet_zivotu = 0;
		std::cout << "Postava " << jmeno << " umira" << "\n";
	}
}