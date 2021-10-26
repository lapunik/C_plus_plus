#include <iostream>
#include <list>
#include <vector>

using namespace std;

string Otoc_slovo(string slovo) 
{
	string otocene_slovo = slovo;

	int velikost = (int)slovo.length();

	for (int i = 0; i < velikost; i++)
	{
		otocene_slovo[i] = slovo[velikost - i - 1];
	}

	return otocene_slovo;
}

string Nahrad_pismeno(string retezec, char co, char za)
{
	for (int i = 0; i < (int)retezec.length(); i++)
	{
		if (retezec[i] == co)
		{
			retezec[i] = za;
		}

	}
	return retezec;
}

string Nahrad_pismeno_na_indexu(string retezec, int index, char znak)
{
	
	retezec[index] = znak;

	return retezec;
}

int Vyskyt(string s, char znak)
{
	int pocet_znaku = 0;

	for (int i = 0; i < (int)s.length(); i++)
	{
		if (s[i] == znak)
		{
			pocet_znaku++;
		}
	}

	return pocet_znaku;
}

void Nahrad_hodnotu_v_poli(int* pole, int velikost, int co, int za)
{
	for (int i = 0; i < velikost; i++)
	{
		if (pole[i] == co)
		{
			pole[i] = za;
		}

	}
}

bool* Porovnani_poli(int* pole1, int* pole2, int velikost) 
{
	bool* pole_porovnani = new bool[velikost];

	for (int i = 0; i < velikost; i++) 
	{
		pole_porovnani[i] = (pole1[i] > pole2[i]);
	}

	return pole_porovnani;
}

int Nejvetsi_rozdil(int* pole, int velikost) 
{

	int max_rozdil = pole[1] - pole[0];

	for (int i = 1; i < velikost-1; i++)
	{
		int rozdil = 0;

		if (pole[i + 1] > pole[i]) 
		{
			rozdil = pole[i + 1] - pole[i];
		}
		else 
		{
			rozdil = pole[i] - pole[i+1];
		}

		if (rozdil > max_rozdil)
		{
			max_rozdil = rozdil;
		}
	}

	return max_rozdil;

}

int Pocet_sudych_list(list<int> seznam)
{
	int sude = 0;

	while(!seznam.empty())
	{
		if (seznam.back() % 2 == 0)
		{
			sude++;
		}
		seznam.pop_back();
	}

	return sude;
}

int Pocet_sudych_vektor(vector<int> vektor) 
{
	int sude = 0;

	for (int i = 0; i < vektor.size(); i++)
	{
		if (vektor.at(i) % 2 == 0)
		{
			sude++;
		}
	}

	return sude;
}

int Pocet_sudych(int* pole, int velikost)
{
	int sude = 0;

	for (int i = 0;i < velikost;i++) 
	{
		if (pole[i]%2 == 0)
		{
			sude++;
		}
	}

	return sude;
}

int Pocet_lichych(int* pole, int velikost)
{
	int liche = 0;

	for (int i = 0; i < velikost; i++)
	{
		if (pole[i] % 2 == 1)
		{
			liche++;
		}
	}

	return liche;
}

int main()
{
	//*
	int velikost = 5;

	int* pole = new int[velikost];

	pole[0] = 4;
	pole[1] = 12;
	pole[2] = 6;
	pole[3] = 1;
	pole[4] = 9;

	//cout << "Pocet sudych: " << Pocet_sudych(pole, velikost) << "\n";
	//cout << "Pocet sudych: " << Pocet_lichych(pole, velikost) << "\n";

	//*/


	/*

	vector<int> vektor;

	vektor.push_back(4);
	vektor.push_back(12);
	vektor.push_back(6);
	vektor.push_back(1);
	vektor.push_back(8);

	cout << "Pocet sudych: " << Pocet_sudych_vektor(vektor) << "\n";

	list<int> seznam;

	seznam.push_back(4);
	seznam.push_back(12);
	seznam.push_back(6);
	seznam.push_back(1);
	seznam.push_back(8);

	cout << "Pocet sudych: " << Pocet_sudych_list(seznam) << "\n";

	//*/

	/*

	int* teploty = new int[velikost];

	teploty[0] = 2;
	teploty[1] = 4;
	teploty[2] = 9;
	teploty[3] = 12;
	teploty[4] = 10;

	cout << "Nejvetsi rozdil: " << Nejvetsi_rozdil(teploty, velikost) << "\n\n";

	//*/

	/*

	int* teploty2 = new int[velikost];

	teploty2[0] = 4;
	teploty2[1] = 6;
	teploty2[2] = 4;
	teploty2[3] = 13;
	teploty2[4] = 1;

	cout << Porovnani, zda jsou teploty v prnim poli vetsi nez ve druhem:\n";

	bool* logicke_pole = Porovnani_poli(teploty, teploty2, velikost);

	for (int i = 0; i < velikost; i++)
	{
		cout << logicke_pole[i] << "\n";
	}

	//*/

	/*
	cout << "\n\nPuvodni pole: \n";

	pole[0] = 3;
	pole[1] = 2;
	pole[2] = 6;
	pole[3] = 2;
	pole[4] = 9;

	for (int i = 0; i < velikost; i++)
	{
		cout << pole[i] << "\n";
	}

	Nahrad_hodnotu_v_poli(2, 4, pole, velikost);

	cout << "\nNahrazeni vsech hodnot v poli s hodnotou 2 za hodnotu 4:\n";
	
	for (int i = 0; i < velikost; i++)
	{
		cout << pole[i] << "\n";
	}
	*/

	//*

	string slovo = "nejkulatoulinkatejsi";

	// upozornit na přetypování ve funkci length !!!!!!!!!!!!

	cout << "\nSlovo obracene: " << Otoc_slovo(slovo) << "\n\n";

	cout << "\nPocet pismen n: " << Vyskyt(slovo,'n') << "\n\n";

	cout << "\nZmena pismena na indexu 0: " << Nahrad_pismeno_na_indexu(slovo,0,'N') << "\n\n";

	cout << "\nZmena pismena i na pismeno I: " << Nahrad_pismeno(slovo,'i','I') << "\n\n";

	//*/

}
