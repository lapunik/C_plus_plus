#include <iostream>
#include <math.h>
using namespace std;

double Soucet(double vstup1, double vstup2)
{
	double soucet = 0;
	soucet = vstup1 + vstup2;
	return soucet;
}

double Rozdil(double vstup1, double vstup2)
{
	double rozdil = 0;
	rozdil = vstup1 - vstup2;
	return rozdil;
}

double Soucin(double vstup1, double vstup2)
{
	double soucin = 0;
	soucin = vstup1 * vstup2;
	return soucin;
}

double Podil(double vstup1, double vstup2)
{
	double podil = 0;
	podil = vstup1 / vstup2;
	return podil;
}

int main()
{
	bool pokracovat = true;
	double a = 0, b = 0;
	while (pokracovat == true)
	{
		cout << "Zadejte prvni cislo: ";
		cin >> a;
		cout << "Zadejte druhe cislo: ";
		cin >> b;

		char operatorfce = '?';
		while (operatorfce != ('/' || '*' || '+' || '-'))
		{
			cout << "Zadejte operaci (/, *, -, +): ";
			cin >> operatorfce;
			if ((operatorfce == ('*')) || (operatorfce == ('-')) || (operatorfce == ('+')))
			{
				break;
			}
			else if ((b == 0) && (operatorfce == '/'))
			{
				cout << "Nulou nelze delit. Zkuste znovu.\n";
			}
			else if ((operatorfce == ('/')) && (b != 0))
			{
				break;
			}
			else
			{
				cout << "Takovou funkci neznam. Zkuste to znovu.\n";
			}
		}

		if (operatorfce == '/')
		{
			cout << "Vysledek je: " << Podil(a, b) << "\n";
		}
		else if (operatorfce == '*')
		{
			cout << "Vysledek je: " << Soucin(a, b) << "\n";
		}
		else if (operatorfce == '-')
		{
			cout << "Vysledek je: " << Rozdil(a, b) << "\n";
		}
		else if (operatorfce == '+')
		{
			cout << "Vysledek je: " << Soucet(a, b) << "\n";
		}
		char dalsi = '?';
		while ((dalsi != 'a') && (dalsi != 'n'))
		{
			cout << "Dalsi vypocet? ((a)no, (n)e):";
			cin >> dalsi;
		}
		if (dalsi == 'n')
		{
			pokracovat = false;
		}
		else if (dalsi == 'a')
		{
			pokracovat = true;
		}
	}
}

