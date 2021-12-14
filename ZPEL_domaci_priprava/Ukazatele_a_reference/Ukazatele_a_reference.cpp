#include <iostream>

using namespace std;

int main()
{
	int a = 15; // vytvoř mi proměnou typu int s názvem "a" a ulož do ni hodnotu 15
	cout << "Normalni int: " << a;
	cout << " je ulozen na adrese: " << &a << "\n"; // pokud chci vidět její adresu, tak použiju referenci & na proměnou


	int *b = new int; //vytvoř nový ukazatel na adresu typu int s názvem "b" a ulož do něj nějakou volnou adresu 
	*b = 7; // na adresu kam ukazuje ukazatel "b" ulož hodnotu 7

	cout << "Dynamicky alokovany int: " << *b; // abych dostal hodnotu, použiju pointer * na proměnou
	cout << " je ulozen na adrese: " << b << "\n\n";

	// Pokud někde použiju slovo "new" musím někde dělat také delete!!!!!!!

	delete b; // uvolním adresu pro další proměnné!
	b = NULL; // koukej do kouta, nikoliv na tu adresu

	// Dvě proměnné koukající na stejné místo v paměti

	b = &a;

	cout << "Normalni int: " << a;
	cout << " je ulozen na adrese: " << &a << "\n";
	cout << "Dynamicky alokovany int: " << *b;
	cout << " je ulozen na adrese: " << b << "\n\n";

	a = 8;

	cout << "Normalni int: " << a;
	cout << " je ulozen na adrese: " << &a << "\n";
	cout << "Dynamicky alokovany int: " << *b;
	cout << " je ulozen na adrese: " << b << "\n";

	// delete b; 
	// b = NULL; 

	// Proč bychom vlastně měli umět pracovat s adresou? → chceme si uděla pole různě velký za behu programu, nebo jako minule.. změna více proměnných ve funkci

}
