#include<iostream>


void dekrement_pole(int* pole, int velikost_pole)
{
	for (int i = 0; i < velikost_pole; i++)
	{
		pole[i] -= 1;
	}
}

int main()
{

	int* pole = new int[5];
	pole[0] = 4;
	pole[1] = 8;
	pole[2] = 3;
	pole[3] = 1;
	pole[4] = 7;

	dekrement_pole(pole, 5);

	for (int i = 0; i < 5; i++)
	{
		std::cout << pole[i] << "\n";
	}
}