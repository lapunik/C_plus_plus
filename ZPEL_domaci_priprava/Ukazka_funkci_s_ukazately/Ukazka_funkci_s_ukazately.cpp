#include <iostream>

using namespace std;

void Prohod_hodnoty_II(int *hodnota1,int *hodnota2)
{
	int pom = *hodnota1;
	*hodnota1 = *hodnota2;
	*hodnota2 = pom;
}

void Prohod_hodnoty(int& hodnota1, int& hodnota2)
{
	int pom = hodnota1;
	hodnota1 = hodnota2;
	hodnota2 = pom;
}

void Inkrement_II(int &hodnota1, int& hodnota2, int& hodnota3)
{
	hodnota1++;
	hodnota2++;
	hodnota3++;

}

int Inkrement(int hodnota)
{
	return hodnota += 1;
}

int main()
{
	int a = 5;
	int b = 6;
	int c = 8;

	Inkrement_II(a,b,c);


	/*

	int a = 15, b = 7, c = 8;

	cout << "a: " << a << "\nb: " << b << "\nc: " << c << "\n";

	a = Inkrement(a);
	b = Inkrement(b);
	c = Inkrement(c);
	cout << "\na: "<< a << "\nb: " << b << "\nc: " << c << "\n";
	
	// Proč je tohle dobrý?

	Inkrement(a,b,c);
	cout << "\na: " << a << "\nb: " << b << "\nc: " << c << "\n";

	//*/

	/*
 
	int a = 3;
	int b = 1;

	cout << "\nf: " << a << "\ng: " << b << "\n";

	Prohod_hodnoty(a, b);

	cout << "\nf: " << a << "\ng: " << b << "\n";

	//*/

	int *a = new int;
	int *b = new int;
	*a = 4;
	*b = 9;

	cout << "\nd: " << *a << "\ne: " << *b << "\n";

	Prohod_hodnoty_II(a, b);

	cout << "\nd: " << *a << "\ne: " << *b << "\n";

	int c = 7; 
	int d = 2;

	cout << "\nd: " << c << "\ne: " << d << "\n";

	Prohod_hodnoty_II(&c, &d);

	cout << "\nd: " << c << "\ne: " << d << "\n";

}
