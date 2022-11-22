#include <iostream>

int main()
{
	int a = 0;

	// IF 
	if (a == 0)
	{
		std::cout << "Jedna";
	}
	else
	{
		std::cout << "Dva";
	}

	// Ternární operátor
	std::cout << (a == 0 ? "Jedna" : "Dva");
}
