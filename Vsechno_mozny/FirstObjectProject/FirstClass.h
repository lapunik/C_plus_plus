#ifndef __FIRSTCLASS__
#define __FIRSTCLASS__
#include <string>

using namespace std;

class FirstClass // deklarace t��dy
{

public:

	struct Text_settings // Zaveden� struktury
	{
		int size;
		string font;
		int count;
	};

	string text; // deklerace atributu (asi vlastnost)
	
	Text_settings fonts; // deklerace struktury jako vlastnosti

	string MakeSomething(string a); // deklarace metody

};


#endif