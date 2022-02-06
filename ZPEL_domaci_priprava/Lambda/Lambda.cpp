#include <iostream>
#include <algorithm>
#include <vector>

enum smer
{
    vzestupne,
    sestupne
};

enum hodnota
{
    vek,
    vyska 
};

struct Osoba {
    int vek;
    float vyska;
};

bool porovnani_veku (Osoba &a,Osoba &b) {
    return a.vek < b.vek;
}

int main() {

    std::vector<Osoba> osoby = 
    {
        {20, 1.78},
        {15, 1.92},
        {32, 1.68},
        {75, 1.72},
        {42, 1.88},

    }; 

    //std::sort(osoby.begin(), osoby.end(), porovnani_veku); // klasické použití sort pro seřazení objektů. Ale funkce porovnani veku je vlastně celkem zbytečná pro celý zbytek kódu, nikde jinde uz ji nepouziju, takže si můžu kód ulečti tím, že použiji pravě lambda funkci
    //                                                       // jednoduše lamdba funce je prostě funcke kterou zapíšu přímo do místa kde ji chci volat.    
    //for (auto os : osoby)
    //{
    //    std::cout << "Osoba - vek: " << os.vek << " | Vyska: " << os.vyska << "\n";
    //}


    // Tady je ta lambda funkce využita právě jako třetí argument funcke sort 
    //std::sort(osoby.begin(), osoby.end(), [](Osoba &a, Osoba &b) {return a.vek < b.vek; });

    //for (auto os : osoby)
    //{
    //    std::cout << "Osoba - vek: " << os.vek << " | Vyska: " << os.vyska << "\n";
    //}

    // vidíme že kód funguje stejně, a nemusel jsem kvůli tomu vytvářet funkci nad main. 

    // hranaté závorky znamenají lambda funkci, ale můžeme je taky použít k předání určité proměnné, která je pro všechny volání funkce stejná, např jestli chceme řadit sestupně, či vzestupně

    //smer s = vzestupne;

    //std::sort(osoby.begin(), osoby.end(), [s](Osoba& a, Osoba& b) {return((s == vzestupne) ? a.vek < b.vek : a.vek > b.vek); });

    //for (auto os : osoby)
    //{
    //    std::cout << "Osoba - vek: " << os.vek << " | Vyska: " << os.vyska << "\n";
    //}

    // použití terárního operátoru nám stále zajistí, že celý kód je na jeden řádek, no není to super?


    //smer s = sestupne;
    //hodnota h = vyska;

    //std::sort(osoby.begin(), osoby.end(), [s,h](Osoba& a, Osoba& b) {return((s == vzestupne) ? ((h == vek) ? a.vek < b.vek : a.vyska < b.vyska) : ((h == vek) ? a.vek > b.vek : a.vyska > b.vyska)); });
    //
    //for (auto os : osoby)
    //{
    //    std::cout << "Osoba - vek: " << os.vek << " | Vyska: " << os.vyska << "\n";
    //}

    // díky terárum jsme dokonce schopni na jednom řádku udělat i výběr, zda chceme srovnání na základně výšky či věku a zda ho chceme sestupně nebo vzestupně
    // btw. tohle už je fakt nečitlnej shit, za tohle by se mělo zavírat do vězení

    smer s = sestupne;
    hodnota h = vyska;

    std::sort(osoby.begin(), osoby.end(), [=](Osoba& a, Osoba& b) {return((s == vzestupne) ? ((h == vek) ? a.vek < b.vek : a.vyska < b.vyska) : ((h == vek) ? a.vek > b.vek : a.vyska > b.vyska)); });

    for (auto os : osoby)
    {
        std::cout << "Osoba - vek: " << os.vek << " | Vyska: " << os.vyska << "\n";
    }

    // hodnoty do lambda funkce mohu předávat buď jednotlivě, nebo můžu předat všechny lokální proměnné které mám v bodu volání lambda funkce.
    // to se dělá pomocí znamnémka =, znaménko & zase předá reference na všechny lokální proměnné 
}