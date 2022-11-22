#include <iostream>

#define DELKA 10

int main()
{

	int* puvodni_radek = new int[DELKA];
	for (int i = 0; i < 10; i++)
	{
		puvodni_radek[i] = i + 1;
	}


	int* radek_prodlouzeny = new int[DELKA+4];

	int* radek = radek_prodlouzeny[];

	for (int i = -2; i < DELKA +2; i++)
	{
		if (i < 0) 
		{
			radek_prodlouzeny[i] = puvodni_radek[0];
		}
		else if (i > DELKA)
		{
			radek_prodlouzeny[i] = puvodni_radek[DELKA-1];
		}
		else 
		{
			radek_prodlouzeny[i] = puvodni_radek[i];
		}
	}


	// Tady můžu indexovat radek mimo svůj rozsah (+/- 2) a stejně mám kód pod kontrolou

}
