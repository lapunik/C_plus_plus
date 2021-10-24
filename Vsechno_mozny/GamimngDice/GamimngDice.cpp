#include <iostream>
#include <string>
#include "DiceClass.h"

using namespace std;

int main()
{

	DiceClass* dice = new DiceClass(10);

	for (int i = 0; i < 10; i++)
	{
		cout << to_string(dice->Throw()) + "  ";

		for (int j = 0; j < 1000000000; j++)
		{
		}
	}
	
	cin.get();
	return 0;
}
