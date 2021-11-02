#include <iostream>

using namespace std;

string Otoc_slovo(string slovo)
{
	string otocene_slovo = slovo;

	int velikost = (int)slovo.length();

	for (int i = 0; i < velikost; i++)
	{
		otocene_slovo[i] = slovo[velikost - i - 1];
	}

	return otocene_slovo;
}

int main()
{
	string slovo = "nejkulatoulinkatejsi";

	cout << "Slovo obracene: " << Otoc_slovo(slovo) << "\n";
}