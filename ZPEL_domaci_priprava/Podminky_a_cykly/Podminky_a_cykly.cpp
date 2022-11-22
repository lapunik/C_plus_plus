#include <iostream>
#include<conio.h>
#include <Windows.h>

using namespace std;

int main()
{

	/* Podmínka IF

	if (podminka)
	{
		prikaz pokud JE podminka splnena
	}
	else if (druha podminka)
	{
		prikaz pokud neni splnena prnvni podminka, ale druhá ano
	}
	else
	{
		prikaz pokud NENI podmínka splnena
	}

	//*/

	/*
	bool podminka = true;
	// podminka = 6 > 5;

	//int hodnota = 15;

	if(podminka)
	//if(!podminka)
	//if(hodnota = 0)
	//if(hodnota = 6)
	//if(hodnota == 15)
	if(hodnota != 15) // >, <, >=, >=
	{
		cout << "Podminka JE splnena\n";
	}
	//else if (hodnota == 15)
	//{
	//	cout << "DRUHA podminka JE splnena\n";
	//}
	else
	{
		cout << "Podminka NENI splnena\n";
	}

	// nula = nepravda, cokoliv jineho = pravda

	//*/

	/* Cyklus WHILE

	while(podminka)
	{
		prikaz;
	}

	//*/

	/*
	
	int hodnota = 0;

	while(hodnota < 10)
	{
		cout << "Zadej hodnotu: ";

		cin >> hodnota;

		cout << "Hodnota je:" << hodnota << "\n";

		//hodnota++;
	}
	//*/

	/*

	bool podminka = true;

	while (podminka)
	{
		cout << "Zadej podminku(0 - konec/1 - pokracuj): ";
		cin >> podminka;
	}

	//*/

	/* Cyklus FOR

	for (podle jake promene; podminka; co ma delat promena)
	{
		prikaz;
	}

	//*/

	/*

	// Hra

	for (int i = 0; i < 10; i++)
	//for (int i = 5; i < 20; i++)
	//for (int i = 0; i < 10; i += 2)
	//for (int i = 9; i >= 0; i--)
	//for (int i = 1; i < 100; i *= 2)
	{
		cout << i << "\n";
	}

	//*/

	/* Faktorial

	int hodnota = 1;
	int faktorial = 1;

	cout << "Zadej cislo: ";

	cin >> hodnota;

	for (int i = 1; i <= hodnota; i++)
	{
		faktorial *= i;
	}

	cout << "Faktorial cisla " << hodnota << " je " << faktorial;

	//*/

	/* Přerušení cyklů:

	cout << "Zacatek programu \n";

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			continue; // přeskoč současnou iteraci
			// break; // přeskoč všechny zbylé iterace
			// return 0; // ukonči celou funkci (v našem případě funkce main)

		}

		cout << i << "\n";
	}

	cout << "Konec programu \n";


	//*/

	/*

	char znak;

	while (true)
	{
		if (_kbhit()) {

			znak = _getch();

			if (int(znak) == 27) // Escape
			{
				break;
			}

			//cout << "Znak: " << znak << " (ASCII:" << (int)znak << ")\n";

		}

		//cout << "nic\n";
		//Sleep(1000);
		//cout << "\033[2J\033[1;1H"; smazani console

	}

	//*/

}