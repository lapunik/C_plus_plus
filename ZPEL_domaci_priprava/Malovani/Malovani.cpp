#include <iostream>

using namespace std;

int main()
{

	char a = 'X';
	char b = '-';

	cout << "Ukol 1:\n\n";

	for (int i = 0; i < 9; i++)
	{
		cout << a;
	}

	cout << "\nUkol 2:\n\n";

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

	cout << "\nUkol 3:\n\n";

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			cout << a;
		}
		cout << '\n';
	}

	//cout << "\nUkol 3:\n\n";

	//for (int j = 1; j < (5*9)+1; j++)
	//{
	//	cout << a;

	//	if((j % 9) == 0)
	//	{
	//		cout << '\n';
	//	}
	//}

	cout << "\nUkol 4:\n\n";

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

	cout << "\nUkol 5:\n\n";

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

	cout << "\nUkol 6:\n\n";

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

	cout << "\nUkol 7:\n\n";

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (i >= j)
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

	cout << "\nUkol 8:\n\n";

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (i >= 4 - j)
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

	cout << "\nUkol 9:\n\n";

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

	cout << "\nUkol 10:\n\n";

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

		}
		cout << "\n";
	}

}