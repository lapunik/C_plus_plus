#include <iostream>
#include <vector>
#include <array>
#include <algorithm>


class Osoba
{
public:
	int IQ;
	std::string jmeno;
	int vek;
};

bool porovnej_IQ(Osoba &a, Osoba &b)
{
	return a.IQ < b.IQ;
}

bool porovnej_vek(Osoba &a, Osoba &b)
{
	return a.vek < b.vek;
}

bool porovnej_jmeno(Osoba& a, Osoba& b)
{
	return a.jmeno < b.jmeno;
}

bool porovnej_IQ_vek(Osoba &a, Osoba &b)
{
	return (a.IQ / a.vek) < (b.IQ / b.vek);
}

//bool porovnej(int a, int b) 
//{
//	return a > b;
//}

int main()
{
	///////////////////// metoda sort potřebuje začátek a konec pole a potom ho krásně srovná podle velikosti //////////////////////////////////////////////

	//int* cisla = new int[5];

	//cisla[0] = 10;
	//cisla[1] = 0;
	//cisla[2] = 8;
	//cisla[3] = 3;
	//cisla[4] = 6;

	//for (int i = 0; i < 5; i++)
	//{
	//	std::cout << cisla[i] << "\n";
	//}

	//std::cout << "\n";

	//std::sort(cisla, cisla + 5);

	//for (int i = 0; i < 5; i++)
	//{
	//	std::cout << cisla[i] << "\n";
	//}

	///////////////////// samozřejmě se dobře hodí i pro srovnání vektoru nebo pole /////////////////////////////////////////////////////////////////////// 	

	//std::vector<int> cisla {1,5,6,88,4,33,25,16,74,5,22,5,12,15,17,6,0};

	//std::array<int, 17> cisla = { 1,5,6,88,4,33,25,16,74,5,22,5,12,15,17,6,0 };

	//for (auto i : cisla) 
	//{
	//	std::cout << i << "\n";
	//}

	//std::cout <<"\n";

	//std::sort(cisla.begin(),cisla.end());

	//for (auto i : cisla)
	//{
	//	std::cout << i << "\n";
	//}

	
	///////////////////// metodu lze ale použít jěště trochu jinak, a to se zadáním i určité porovnávací funcke //////////////////////////////////////////////

	//int* cisla = new int[5];

	//cisla[0] = 10;
	//cisla[1] = 0;
	//cisla[2] = 8;
	//cisla[3] = 3;
	//cisla[4] = 6;

	//for (int i = 0; i < 5; i++)
	//{
	//	std::cout << cisla[i] << "\n";
	//}

	//std::cout << "\n";

	//std::sort(cisla, cisla + 5,porovnej); // vytvořili jsme si fuknci porovnej a nechali jsme ji pole seřadit od největšího čísla, k čemu to ale může být dobré? např pro třídění objektů podle určité vlastnosti

	//for (int i = 0; i < 5; i++)
	//{
	//	std::cout << cisla[i] << "\n";
	//}

	///////////////////// srovnani trid podle urcite vlastnosti v poli //////////////////////////////////////////////

	Osoba* osoby = new Osoba[5]
	{
		{ 120,"Karel",25 },
		{ 101,"Zikmund",32 },
		{ 88,"Pepa",54 },
		{ 95,"Anna",15 },
		{ 115,"Jindra",75 }

	};

	for (int i = 0; i < 5; i++)
	{
		std::cout << osoby[i].jmeno << "\t" << osoby[i].vek << " let\t"<< osoby[i].IQ << " iq\n";
	}

	std::cout << "\n";

	// std::sort(osoby, osoby + 5); // tento kód by nyní nepochodil. Sort neví jestli chceme seřadit třídu podle stringu jméno, nebo podle věku, či IQ... proto musíme vytvořit funkci kde to funcki sort objasníme

	std::sort(osoby, osoby + 5,porovnej_vek); // pozor!! ve funkcích musí být pro vatupy reference & aby nám funkce sort byla schopna pole setřídit


	for (int i = 0; i < 5; i++)
	{
		std::cout << osoby[i].jmeno << "\t" << osoby[i].vek << " let\t" << osoby[i].IQ << " iq\n";
	}

	std::cout << "\n";

	std::sort(osoby, osoby + 5, porovnej_IQ); // taky můžu porovnávat IQ


	for (int i = 0; i < 5; i++)
	{
		std::cout << osoby[i].jmeno << "\t" << osoby[i].vek << " let\t" << osoby[i].IQ << " iq\n";
	}

	std::cout << "\n";

	std::sort(osoby, osoby + 5, porovnej_IQ_vek); // nebo klidně mohu porovnávat nějaký matematický výraz z více vlastností 


	for (int i = 0; i < 5; i++)
	{
		std::cout << osoby[i].jmeno << "\t" << osoby[i].vek << " let\t" << osoby[i].IQ << " iq\n";
	}

	std::cout << "\n";

	std::sort(osoby, osoby + 5, porovnej_jmeno); // taky můžu porovnávat IQ


	for (int i = 0; i < 5; i++)
	{
		std::cout << osoby[i].jmeno << "\t" << osoby[i].vek << " let\t" << osoby[i].IQ << " iq\n";
	}

	std::cout << "\n";
}