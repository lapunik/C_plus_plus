#include <iostream>

using namespace std;

int main()
{
	// Až budueme dělat hru

	char a = 'X';
	char b = '-';

	/* Ukol 1

	for (int i = 0; i < 9; i++)
	{
		cout << a;
	}
	
	//*/

	/* Ukol 2

	for (int i = 0; i < 9; i++)
	{
		if (i == 4)
		{
			cout << b;
		}
		else
		{
			cout << a;
		}
	}
	//*/

	/* Ukol 3

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 9; i++)
		{
				cout << a;
		}
		cout << '\n';
	}

	//*/

	/* Ukol 4

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 9; i++)
		{

			if (j == 2)
			{
				cout << b;
			}
			else
			{
				cout << a;
			}
		}
		cout << '\n';
	}

	//*/

	/* Ukol 5

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 9; i++)
		{

			if ((j == 2) || (i == 4))
			{
				cout << b;
			}
			else
			{
				cout << a;
			}
		}
		cout << '\n';
	}

	//*/

	/* Ukol 6

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (i > j)
			{
				cout << b;
			}
			else
			{
				cout << a;
			}
		}
		cout << '\n';
	}

	//*/

	/* Ukol 7

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (i>=j)
			{
				cout << a;
			}
			else
			{
				cout << b;
			}
		}
		cout << '\n';
	}

	//*/

	/* Ukol 8

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (i>=4-j)
			{
				cout << a;
			}
			else
			{
				cout << b;
			}
		}
		cout << '\n';
	}

	//*/

	/* Ukol 9

	for (int j = 5; j < 10; j++)
	{
		for (int i = 1; i < 10; i++)
		{
			if ((j < 10 - i) || (j < i))
			{
				cout << "-";
			}
			else
			{
				cout << "X";
			}
		}
		cout << "\n";
	}

	//*/

	/* Ukol 10

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			if ((j % 2 == 0) && (i % 2 == 0))
			{
				cout << "X";
			}
			else if ((j % 2 != 0) && (i % 2 != 0))
			{
				cout << "X";
			}
			else
			{
				cout << "-";
			}

			//if (j % 2 == 0)
			//{
			//	if (i % 2 == 0)
			//	{
			//		cout << "X";
			//	}
			//	else
			//	{
			//		cout << "-";
			//	}
			//}
			//else
			//{
			//	if (i % 2 == 0)
			//	{
			//		cout << "-";
			//	}
			//	else
			//	{
			//		cout << "X";
			//	}
			//}

		}
		cout << "\n";
	}

	//*/
}