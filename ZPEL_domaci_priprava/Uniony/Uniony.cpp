#include <iostream>

using namespace std;

union Obecny_typ
{
	int typ_int;
	double typ_double;
	char typ_char;

};

/*
union mena
{
	int koruna;
	double euro;

};
//*/

int main()
{
	Obecny_typ a;

	a.typ_char = '+';
	cout << "Pouzivam promenou \"a\" jako char, a: " << a.typ_char << "\n";

	a.typ_int = 15;
	cout << "Pouzivam promenou \"a\" jako int, a: " << a.typ_int << "\n";

	a.typ_double = 6.4;
	cout << "Pouzivam promenou \"a\" jako double, a: " << a.typ_double << "\n";

	//cout << "Pouzivam promenou \"a\" jako char, a: " << a.typ_char << "\n";

	/*
	mena penize;
	penize.koruna = 159;
	penize.euro = 7.22;
	//*/
}
