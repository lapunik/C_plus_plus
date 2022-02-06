#pragma once

#include <iostream>
#include <string>

class Postava
{

	struct Zbran
	{
		std::string nazev;
		int poskozeni;
	};

	struct Zbroj
	{
		std::string nazev;
		int durabilita;
	};


private:
	
	int const max_pocet_zivotu = 100;

public:
	
	Postava(std::string jmeno, std::string rasa);
	std::string jmeno;
	int pocet_zivotu = max_pocet_zivotu;
	std::string rasa;
	//int poskozeni = 10;
	//int zbroj = 5;
	void Predstav_se();
	void Ukaz_pocet_zivotu();
	void Utok(Postava &oponent);
	void Obrana(int poskozeni);
	Zbran zbran = { "pesti",1 };
	Zbroj zbroj = {"zadna",0};


};

