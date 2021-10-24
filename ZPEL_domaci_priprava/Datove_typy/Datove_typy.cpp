#include <iostream>
using namespace std;

int main()
{
	/* Datové typy

	// Pojmy delkerace/ inicializace (založení/naplnění proměnné)

	int celociselny = 5; // Celočíselný (1, 2, -6cvi23cvi, 53, 666)
	float desetinny = 5.5; // Desetinný (1.2, 55.6, 7.999) DESETINNÁ TEČKA(nikoliv čárka, inicializovat s tečkou)
	double desetinny_presnejsi = 5.5;// Desetinný s větší přesností, ale i tak je omezená přesnost
	char znak = 'a'; // Znakový (a, b, c, +, :) → ASCII tabulka
	string textovy_retezec = "Nejkulatoulinkatejsi"; // Textový řětězec (pole znaků)
	bool logicky = true; // Logický typ

	//*/

	/* Aritmetické operace

	int hodnota1 = 5;
	int hodnota2 = 3;
	int vysledek;

	vysledek = hodnota1 + hodnota2;
	vysledek = hodnota1 - hodnota2;
	vysledek = hodnota1 * hodnota2;
	vysledek = hodnota1 / hodnota2; //nezaokrouhluje se, ale ořízne!
	vysledek = hodnota1 % hodnota2;

	vysledek = pow(hodnota1, hodnota2); // mocnina
	vysledek = sqrt(hodnota1); // druhá mocnina

	cout << "Vysledek: " << vysledek;

	// změnit int na double, ukázat chybu při pokusu uložit do int promene nějaky double vypocet
	// zkrácení zápisů (i++, ++i, vysledek += 5)
	// připomenout konstatny

	//*/

	//*/

	/* ASCII tabulka

	//char znak = 97;
	char znak = 'a';

	cout << "Znak: " << znak << "\n" ;

	// malování okénka

	cout << "┌┬┐" << "├┼┤" << "└┴┘" << "\n";


	cout << 218 << 194 << 191 << "\n";
	cout << 195 << 197 << 180 << "\n";
	cout << 192 << 193 << 217 << "\n";



	cout << (char)218 << (char)194 << (char)191 << "\n";
	cout << (char)195 << (char)197 << (char)180 << "\n";
	cout << (char)192 << (char)193 << (char)217 << "\n";

	//*/


	//* String aritmeticke operace

	string text_a = "Ahoj ";
	string text_b = "Vojto";

	string vysledek = text_a + text_b;

	cout << vysledek;

	//*/

}