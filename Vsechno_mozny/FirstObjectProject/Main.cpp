#include <iostream>
#include "FirstClass.h"

using namespace std; // abychom nemuseli ps�t std::cout << "Hello" << std::endl;.... takhle n�m st��� jen cout << "Hello"; 

int main()
{
	FirstClass fc;

	fc.text = "Hello ";
	fc.fonts.count = 3;

	for (int i = 0; i < fc.fonts.count; i++) 
	{
	cout << fc.MakeSomething("Vojta");
	}
	cout << "Get string: ";

	cin >> fc.text;
	cout << fc.MakeSomething("Vojta");
	
	cin.get();
	return 0;
}