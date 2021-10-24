#include <iostream>

using namespace std;

void Zmena_ukazatele_ve_funkci_NEFUNKCNI(int *adresa)
{
	adresa = new int;
	*adresa = 5;
	cout << "Adresa hodnoty: " << adresa << "\nAdresa adresy: " << &adresa << "\nHodnota: " << *adresa << "\n\n";
}

void Zmena_ukazatele_ve_funkci(int **adresa)
{
	*adresa = new int;
	**adresa = 5;
	cout << "Adresa hodnoty: " << *adresa << "\nAdresa adresy: " << adresa << "\nHodnota: " << **adresa << "\n\n";
}

void Zmena_ukazatele_ve_funkci_II(int *&adresa)
{
	adresa = new int;
	*adresa = 5;
	cout << "Adresa hodnoty: " << adresa << "\nAdresa adresy: " << &adresa << "\nHodnota: " << *adresa << "\n\n";
}

void Third(int *hodnota)
{
	cout << "Hodnota ve funkci: " << *hodnota << "\nAdresa hodnoty ve funkci: " << hodnota << "\n\n";
}

void Second(int& hodnota)
{
	cout << "Hodnota ve funkci: " << hodnota << "\nAdresa hodnoty ve funkci: " << &hodnota << "\n\n";
}

void First(int hodnota)
{
	cout << "Hodnota ve funkci: " << hodnota << "\nAdresa hodnoty ve funkci: " << &hodnota << "\n\n";
}

int main()
{

	/*

	int a = 5; // do proměnné "a" ulož hodnotu 5
	cout << "Hodnota \"a\": " << a << " Adresa \"a\": " <<  &a << "\n";


	int *b = new int; // vytvoř ukazatel "b" na nějakou adresu (na část paměti)
	*b = 8; // na místo v paměti ulož hodnotu 8
	cout << "Hodnota \"b\": " << *b << " Adresa \"b\": " << b << "\n";


	int c = a;// do proměnné "c" ulož stejnou hodnotu jako je hodnota v proměnné "a"
	cout << "Hodnota \"c\": " << c << " Adresa \"c\": " << &c << "\n"; // hodnota je stejná jako u proměnné "a", ale adresa je jiná!


	int &d = a;// do adresy proměnné "d" ulož stejnou adresu jako má v proměnná "a" (to znamená, že proměná "a" i "d" bude uložena na stejné adrese, tj. změna jedné proměnné způsobí změnu i druhé proměnné)
	cout << "Hodnota \"d\": " << d << " Adresa \"d\": " << &d << "\n"; // adresa je stejná jako u proměnné "a", a tím pádem i hodnota musí být stejná
	d = 6; // při změně hodnoty proměnné "d" se mění také hodnota proměnné "a", protože jsou uloženy na stejné adrese
	cout << "Hodnota \"d\": " << d << " Adresa \"d\": " << &d << "\n";
	cout << "Hodnota \"a\": " << a << " Adresa \"a\": " << &a << "\n";


	int *e = new int; // vytvoř ukazatel "e" na nějakou adresu(na část paměti)
	*e = a; // na adresu "e" ulož hodnotu proměnné "a"
	cout << "Hodnota \"e\": " << *e << " Adresa \"e\": " << e << "\n"; // hodnota je stejná jako u proměnné "a", ale adresa je jiná!
	*e = 7; // pokud změním hodnotu na adrese, na kterou odkazuje ukazatel e, nijak to nezmění hodnotu "a", či "d"
	cout << "Hodnota \"e\": " << *e << " Adresa \"e\": " << e << "\n";
	cout << "Hodnota \"a\": " << a << " Adresa \"a\": " << &a << "\n";


	int* f = &a; // vytvoř ukazatel "f" na adresu, na které je uložena hodnota proměnné "a"
	cout << "Hodnota \"f\": " << *f << " Adresa \"f\": " << f << "\n"; // adresa je stejná jako u proměnné "a", a tím pádem i hodnota musí být stejná
	*f = 4; // pokud změním hodnotu na adrese, na kterou odkazuje ukazatel f, změní se i hodnota "a", resp. "d"
	cout << "Hodnota \"f\": " << *f << " Adresa \"f\": " << f << "\n";
	cout << "Hodnota \"a\": " << a << " Adresa \"a\": " << &a << "\n";

	//*/

	/*

	int a = 5;
	int *p = &a;
	int **p_2 = &p;
	int ***p_3 = &p_2;

	cout << "Hodnota: " << a << "\nAdresa hodnoty: " << p << "\nAdresa na adresu hodnoty: " << p_2 << "\nAdresa na adresu adresy hodnoty: " << p_3 << "\n\n";

	cout << "Hodnota: " << *p << "\nAdresa hodnoty: " << *p_2 << "\nAdresa na adresu hodnoty: " << *p_3 << "\n\n";

	cout << "Adresa hodnoty: " << &a << "\nAdresa na adresu hodnoty: " << &p << "\nAdresa na adresu adresy hodnoty: " << &p_2 << "\nAdresa na adresu adresy k adrese hodnoty: " << &p_3 << "\n\n";

	//*/

	/*

	int a = 5;

	cout << "Hodnota: " << a << "\nAdresa hodnoty: " << &a << "\n\n";

	First(a); // funkci předám proměnou "a", kde funkce si vezme pouze hodnotu. Ve funkci má parametr stejnou hodnotu jako je hodnota "a", ale adresa parametru a "a" je jiná!
	Second(a); // funkci předám proměnou "a", kde funkce si vezme adresu proměnné "a" (tudíž i hodnotu). Ve funkci má parametr stejnou hodnotu jako je hodnota "a", ale i adresa je stejná!
	Third(&a); // funkci předávám adresu proměnné "a", kde funkce tuto adresu ukládá do parametru typu pointer. Ve funkci má potom parametr stejnou hodnotu jako je hodnota "a", ale i adresa je stejná!

	int *b = new int;
	*b = 7;

	First(*b);
	Second(*b);
	Third(b);

	//*/

	//*

	int *a = NULL;

	cout << "Adresa hodnoty: " << a << "\nAdresa adresy: " << &a << "\nHodnota: bez hodnoty" << "\n\n";

	//Zmena_ukazatele_ve_funkci(&a);
	Zmena_ukazatele_ve_funkci_II(a);
	//Zmena_ukazatele_ve_funkci_NEFUNKCNI(a);

	cout << "Adresa hodnoty: " << a << "\nAdresa adresy: " << &a << "\nHodnota: " << *a << "\n\n";

	//*/

}
