#include <iostream>

using namespace std;

int main()
{
	double hodnota1 = 0.0;
	char operace = '_';
	double hodnota2 = 0.0;
	double vysledek;

	bool dalsi_vypocet = true;

	while (dalsi_vypocet)
	{

		cout << "Zadej hodnotu 1: ";
		cin >> hodnota1;

		cout << "Zadej hodnotu 2: ";
		cin >> hodnota2;

		bool neznama_operace = true;

		while (neznama_operace)
		{

			cout << "Zadej operaci (+,-,*,/): ";
			cin >> operace;

			if (operace == '+')
			{
				vysledek = hodnota1 + hodnota2;
				neznama_operace = false;
			}
			else if (operace == '-')
			{
				vysledek = hodnota1 - hodnota2;
				neznama_operace = false;
			}
			else if (operace == '*')
			{
				vysledek = hodnota1 * hodnota2;
				neznama_operace = false;
			}
			else if (operace == '/')
			{
				vysledek = hodnota1 / hodnota2;
				neznama_operace = false;
			}
			else
			{
				cout << "Neznam operaci\n";
			}
		}

		if ((hodnota2 == 0) && (operace == '/'))
		{
			cout << "Nulou nelze delit. \n";
		}
		else
		{
			cout << "Vysledek: " << vysledek << "\n";
		}

		bool neznama_hodnota = true;

		while (neznama_hodnota)
		{
			char zadani;

			cout << "Dalsi vypocet? ((n)e, (a)no): ";
			cin >> zadani;

			if (zadani == 'a')
			{
				neznama_hodnota = false;
				dalsi_vypocet = true;
			}
			else if (zadani == 'n')
			{
				neznama_hodnota = false;
				dalsi_vypocet = false;
			}
			else
			{
				cout << "Nevim co po me chces.\n";
			}

		}

	}
}
