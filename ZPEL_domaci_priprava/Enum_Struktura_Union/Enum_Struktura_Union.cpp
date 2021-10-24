#include <iostream>

using namespace std;

union mena
{
	int dolar;
	int koruna;
	double libra;
};

int main()
{
	mena m;

	//cout << "Dolar: " << m.dolar << " Koruna: " << m.koruna << "Libra: " << m.libra << endl;

	m.dolar = 5;

	cout << "Dolar: " << m.dolar << " Koruna: " << m.koruna << "Libra: " << m.libra << endl;

	m.koruna = 150;

	cout << "Dolar: " << m.dolar << " Koruna: " << m.koruna << "Libra: " << m.libra << endl;

	m.libra = 4.5;

	cout << "Dolar: " << m.dolar << " Koruna: " << m.koruna << "Libra: " << m.libra << endl;
}
