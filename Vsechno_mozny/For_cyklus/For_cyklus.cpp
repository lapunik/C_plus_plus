#include <iostream>

int main()
{
	int* pole = new int[5];

	pole[0] = 0;
	pole[1] = 2;
	pole[2] = 6;
	pole[3] = 8;
	pole[4] = 10;

	for (int* i = pole; i < pole + 5; i++)
	{
		std::cout << *i << "\n";
	}

	int pole2[] = { 0,2,4,6,8};

	for (auto i : pole2) 
	{
		std::cout << i;
	}
}