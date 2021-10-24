#include <iostream>

using namespace std;

int main()
{
	double sirka = 0.0;
	double vyska = 0.0;

	cout << "Zadej sirku [cm]: ";
	cin >> sirka;

	cout << "Zadej vysku [cm]: ";
	cin >> vyska;

	cout << "Obdelnik o velikosti " << sirka << "x" << vyska << " ma obvod [mm]: " << ((2 * vyska) + (2 * sirka)) * 10 << "cm a obsah: " << (vyska * sirka) * 10 << "cm^2";

}
