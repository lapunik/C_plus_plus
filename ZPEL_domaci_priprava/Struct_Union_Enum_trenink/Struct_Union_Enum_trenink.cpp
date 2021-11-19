#include <iostream>

using namespace std;

struct Osoba
{
	string jmeno;
	int vek;
	string zamestnani;
};

void Vypis(Osoba o) 
{
	cout << "Osoba se jmenuje " << o.jmeno << " je mu " << o.vek << " let a pracuje jako " << o.zamestnani << ".\n";
}

int main()
{
	Osoba osoba = { "Vojta",24,"student" };
	Vypis(osoba);
}