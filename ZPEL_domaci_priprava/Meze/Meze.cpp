#include <iostream>

using namespace std;

int Faktorial(int hodnota)
{
	//if ((hodnota < 7) && (hodnota >= 0))
	//{

		int faktorial = 1;

		for (int i = 2; i <= hodnota; i++)
		{
			faktorial *= i;
		}

		return faktorial;

	//}
	//else 
	//{
	//	return -1;
	//}
}

int main()
{

	int hodnota = 1;

	cout << "Zadej cislo: ";
	cin >> hodnota;

	int faktorial = Faktorial(hodnota);

	//if (faktorial == -1)
	//{
	//	cout << "Faktorial nelze spocitat.";
	//}
	//else
	//{
		cout << "Faktorial cisla " << hodnota << " je " << faktorial;
	//}

}
