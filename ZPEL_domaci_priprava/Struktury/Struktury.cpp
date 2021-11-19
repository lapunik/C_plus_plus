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

//*
struct Vybaveni
{
	string zdroj;
	string zbran;

};
//*/

struct Postava
{
	string jmeno;
	int zivoty;
	string rasa;
	//Rasa rasa;
	Vybaveni vybaveni;

};

void ziskej_informace_zivoty(Postava p)
{
	cout << "Postava " << p.jmeno << "(" << p.rasa << ") ma aktualne " << p.zivoty << " zivotu.\n";
}

//*
void ziskej_informace_vybaveni(Postava p)
{
	cout << "Postava " << p.jmeno << "(" << p.rasa << ") ma " << p.vybaveni.zbran << " a " << p.vybaveni.zdroj << ".\n";
}
//*/

/*
string Cislo_na_rasu(Rasa r)
{
	switch (r)
	{
	case clovek:
		return "clovek";
	case elf:
		return "elf";
	case trpaslik:
		return "trpaslik";
	case skret:
		return "skret";
	case hobit:
		return "hobbit";
	default:
		return "neznam";
	}
}
//*/

int main()
{
	Postava p1;
	p1.jmeno = "Legolas";
	p1.zivoty = 100;
	p1.zivoty = 100;
	p1.rasa = "elf";

	Postava p2 = { "Gimli", 150, "trpaslik" };

	ziskej_informace_zivoty(p1);
	ziskej_informace_zivoty(p2);

	//*
	p1.vybaveni.zbran = "luk";
	p1.vybaveni.zdroj = "elfsky habit";
	p2.vybaveni.zbran = "sekera";
	p2.vybaveni.zdroj = "platova zbroj";

	ziskej_informace_vybaveni(p1);
	ziskej_informace_vybaveni(p2);
	//*/

}
