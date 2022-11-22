#include <iostream>
#include <string>

std::string otoc_slovo(std::string retezec)
{
	std::string retezec_otoceny = retezec;

	int velikost_retezce = (int)retezec.size();

	for (int i = 0; i < velikost_retezce; i++)
	{
		retezec_otoceny[i] = retezec[velikost_retezce - i - 1];
	}
	return retezec_otoceny;
}

int main()
{
	std::string slovo;
	std::cin >> slovo;
	int index;
	std::cin >> index;
	char znak;
	std::cin >> znak;
	std::cout << otoc_slovo(slovo);
}