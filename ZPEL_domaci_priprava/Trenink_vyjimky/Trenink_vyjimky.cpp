#include <iostream>

using namespace std;

int Maximum_2Dpole(int pole[3][3])
{
	int max = pole[0][0];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (pole[i][j] < 0) 
			{
				throw "Zaporna hodnota v poli";
			}

			if (max < pole[i][j])
			{
				max = pole[i][j];
			}
		}
	}

	return max;
}

int Soucet_rady(int hodnota)
{
	if ((hodnota > 10) || (hodnota < 0))
	{
		throw "Hodnota mimo rozsah.";
	}
	else
	{
		int soucet = 0;

		for (int i = 1; i <= hodnota; i++)
		{
			soucet += i;
		}

		return soucet;
	}

}

int main()
{
	/*
	try
	{
		cout << Soucet_rady(4) << "\n";
	}
	catch (const char* text)
	{
		cout << text;
	}
	//*/

	
	int pole[3][3] = {1,8,15,3,7,6,13,1,0};

	try
	{
		std::cout << Maximum_2Dpole(pole);
	}
	catch (const char* text)
	{
		cout << text;
	}

	

	
}