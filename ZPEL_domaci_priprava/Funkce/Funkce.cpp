#include <iostream>

using namespace std;

void Inkrement_jinak(int &hodnota) 
{
    //hodnota = 5;
    hodnota++;
}

int Inkrement(int hodnota) 
{
    return hodnota + 1;
}

void Lepsi_pozdrav(string jmeno, int vek, string povolani) 
{
    cout << "Ahoj " << jmeno << ", vitam te. Je ti " << vek << " let a jsi zamestnany jako " << povolani << ".\n";

}

int Faktorial(int hodnota)
{
    int vysledek = 1;

    for (int i = 1; i <= hodnota; i++)
    {
        vysledek *= i;
    }
    return vysledek;
}

int Soucet(int a, int b) 
{
    return a + b;
}

void Vypis_vysledku(int vysledek)
{
    cout << "Vysledek je: " << vysledek << "\n";
}

void Pozdrav()
{
    cout << "Ahoj\n";
}

int main()
{
    Pozdrav();

    int hodnota1 = 7;
    int hodnota2 = 3;

    int vysledek = Soucet(hodnota1, hodnota2);

    Vypis_vysledku(vysledek);

    vysledek = Faktorial(hodnota1);

    Vypis_vysledku(vysledek);

    Lepsi_pozdrav("Vojta", 24, "student");

    cout << "Hodnota je: " << hodnota1 << "\n";

    hodnota1 = Inkrement(hodnota1);

    cout << "Hodnota je: " << hodnota1 << "\n";

    Inkrement_jinak(hodnota1);

    cout << "Hodnota je: " << hodnota1 << "\n";
}
