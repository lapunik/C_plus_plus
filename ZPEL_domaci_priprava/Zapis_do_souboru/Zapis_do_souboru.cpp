#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream nazev_promene;

	//*
	nazev_promene.open("textovy_soubor.txt", ios::out);

	nazev_promene << "Nejakej text\n";
	//nazev_promene << "Nejakej uplne jinej text\n";
	//nazev_promene << "Nejakej text " << "Nejakej text2";
	
	nazev_promene.close(); // Dokud nezavřu, tak se text kupí
	//*/

	// Znovu otevření stejného souboru jako ios::out 
	//*
	nazev_promene.open("textovy_soubor.txt", ios::out); // Když zavřu a zase otevřu, tak se ale soubor opět přepíše, protože ios::out

	nazev_promene << "Nejakej uplne jinej text\n";
	
	nazev_promene.close();
	//*/

	// Otevření nového souboru
	//*
	nazev_promene.open("textovy_soubor2.txt", ios::out);

	nazev_promene << "Nejakej uplne jinej text\n";

	nazev_promene.close();
	//*/

	// Otevření pro připsání (ios::app)
	//*		
	nazev_promene.open("textovy_soubor.txt", ios::app); // Soubor se nepřepisuje, text se přidává na konec

	nazev_promene << "Dalsi pridanej text\n";

	nazev_promene.close();
	//*/


	// ukázka bezpečného volání s is_open()
	//* 
	
	nazev_promene.open("textovy_soubor.txt", ios::out);

	if (nazev_promene.is_open()) // ověření otevření 
	{
		std::cout << "Zapis do souboru proveden\n";
		//nazev_promene << "Nejakej text\n";
	}
	else
	{
		std::cout << "Soubor neni otevren\n";
	}

	nazev_promene.close();

	//*/


	// Otevření jako pro čtení (ios::in)
	//*		
	nazev_promene.open("textovy_soubor.txt", ios::in); // Soubor se nepřepisuje, text se přidává na konec

	string text;

	nazev_promene >> text;

	cout << text;

	nazev_promene.close();
	//*/

	// Čtení celého souboru
	//*
	nazev_promene.open("textovy_soubor.txt", ios::in); // Soubor se nepřepisuje, text se přidává na konec

	string text((istreambuf_iterator<char>(nazev_promene)), istreambuf_iterator<char>());

	cout << text;

	nazev_promene.close();

	//*/
}