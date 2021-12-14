#include<limits>
#include<iostream>
#include<string>

using namespace std;

class Knihy
{
	int police[20];
	int diference;
public:
	void nastav_diferenci(int dif)
	{
		diference = dif;
	}

	void nastav_prvni_polici(int pocet)
	{
		police[0] = pocet;
	}

	int nacti_hodnotu(std::string vyzva, int min, int max) {
		int pom = 0;
		do {
			cout << vyzva << "\n";
			cin >> pom;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while ((pom < min) || (pom > max));
		return pom;
	}


	//Vytvorte funcki: 
	//a)pole polic naplni pocty knih dle aritmeticke posloupnosti(prvni prvek je v poli nastaven, diference je predana parametrem)
	//b)vypise pocty knihv jednotlivych policich

	void pocty_knih()
	{
		std::cout << police[0] << " ";
		for (int i = 1; i < 20; i++)
		{
			police[i] = police[(i - 1)] + diference;
			std::cout << police[i] << " ";
		}

	}

	void soucet_prumer()
	{
		int soucet = 0;
		double prumer = 0;
		for (int i = 0; i < 20; i++)
		{
			soucet = soucet + police[i];
		}
		prumer = soucet / 20.0;
		std::cout << "Soucet: " << soucet << "\n";
		std::cout << "Prumer: " << prumer;
	}

};

int main()
{
	Knihy knihy;
	knihy.nastav_prvni_polici(9);
	knihy.nastav_diferenci(5);
	knihy.pocty_knih();
	knihy.soucet_prumer();

}