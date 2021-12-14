#include <iostream>
#include "Postava.h"

using namespace std;

int main()
{
    Postava p1("Legolas", "elf");
    Postava p2("Saruman", "carodej");

    //p1.Predstav_se();
    //p2.Predstav_se();

    //p2.Ukaz_pocet_zivotu();
    //p1.Utok(p2);
    //p2.Ukaz_pocet_zivotu();
    
    p1.zbran = {"elfsky luk",25};
    p1.zbroj = { "elfska platova zbroj",15};

    p2.zbran = { "kouzelna hul", 40 };
    p2.zbroj = { "magicky habit", 3 };

    //p2.Ukaz_pocet_zivotu();
    //p1.Utok(p2);
    //p2.Ukaz_pocet_zivotu();


    while ((p1.pocet_zivotu > 0) && (p2.pocet_zivotu > 0)) 
    {
    
        p1.Utok(p2);
        p2.Ukaz_pocet_zivotu();


        if (p2.pocet_zivotu < 1) 
        {
            break;
        }

        cout << "\n";

        p2.Utok(p1);
        p1.Ukaz_pocet_zivotu();

        cout << "\n";
    
    }




    //Postava* p3 = new Postava("Aragorn", "clovek");
    //p3->Predstav_se();

}