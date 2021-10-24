#include <iostream>

using namespace std;

int Mocnina(int zaklad, int exponent)
{
	int hodnota = zaklad;

	for (int i = 1; i < exponent; i++)
	{
		zaklad *= hodnota;
	}
	return zaklad;
}

void Dvojnasobek(int& hodnota)
{
	hodnota *= 2;
}

int Mensi_hodnota(int a, int b)
{
	return (a < b ? a : b);

	/*
	if (a < b) 
	{
		return a;
	}
	else 
	{
		return b;
	}
	*/
}

int Druha_mocnina(int zaklad)
{
	return zaklad * zaklad;
}

int main()
{
	cout << Mensi_hodnota(19, 18) << "\n";

	cout << Mocnina(2, 8) << "\n";

	int hodnota = 15;

	cout << hodnota << "\n";

	Dvojnasobek(hodnota);

	cout << hodnota << "\n";

}
