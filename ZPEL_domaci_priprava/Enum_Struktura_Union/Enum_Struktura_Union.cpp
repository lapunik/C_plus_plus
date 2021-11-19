#include <iostream>

using namespace std;

enum Rasa
{
	clovek,
	elf,
	trpaslik,
	skret,
	hobit,
	
};

struct Vybaveni
{ 
	string zdroj;
	string zbran;

};

struct Postava
{
	string jmeno;
	Rasa rasa;
	int zivoty;
	Vybaveni vybaveni;

	
};

void ziskej_informace_zivoty(Postava p)
{
	cout << "Postava " << p.jmeno << "(" << p.rasa << ") ma aktualne " << p.zivoty << " zivotu.\n";
}

void ziskej_informace_vybaveni(Postava p)
{
	cout << "Postava " << p.jmeno << "(" << p.rasa << ") ma " << p.vybaveni.zbran << " a " << p.vybaveni.zdroj << ".\n";
}

int main()
{
	Postava p1;
	p1.jmeno = "Legolas";
	p1.rasa = elf;
	p1.zivoty = 100;
	p1.vybaveni.zbran = "luk";
	p1.vybaveni.zdroj = "elfsky habit";

	Postava p2;
	p2.jmeno = "Gimli";
	p2.rasa = trpaslik;
	p2.zivoty = 150;
	p2.vybaveni.zbran = "sekera";
	p2.vybaveni.zdroj = "platova zbroj";

	ziskej_informace_zivoty(p1);	
	ziskej_informace_zivoty(p2);

	ziskej_informace_vybaveni(p1);
	ziskej_informace_vybaveni(p2);


}
