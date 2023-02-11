// PythagorejskeTrojuhelniky.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//
#include <iostream>
#include <string>
#include <limits>
#include <cmath>

int nacti_hodnotu(std::string vyzva, int min, int max)
{
    int hodnota = 0;

    std::cout << vyzva << '\n';
    std::cin >> hodnota;

    while (std::cin.fail() || (hodnota > max) || (hodnota < min))
    {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << vyzva << '\n';
        std::cin >> hodnota;
    }

    return hodnota;
}

int pocitejA(int p, int q)
{
    return (q * q - p * p);
}

int pocitejB(int p, int q)
{
    return 2 * q * p;
}

int pocitejC(int p, int q)
{
    return (p * p + q * q);
}

bool platiPythagorovaVeta(int a, int b, int c)
{
    if (c == sqrt(a * a + b * b))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void vypisVysledky(int* koeficienty, int* strany, bool overeni)
{
    std::cout << "Zadane cislo p = " << koeficienty[0] << "\nZadane cislo q = " << koeficienty[1] << "\n";
    std::cout << "Strany trojuhelnika jsou:\n";
    std::cout << "odvesna a = " << strany[0] << "\nodvesna b = " << strany[1] << "\nprepona c = " << strany[2] << "\n";
    std::cout << "Pro trojuhelnik " << (overeni?"plati":"neplati") << " Pythagorova veta.\n";

    
}

class PTrojuhelnik 
{
private:

    int p = 0;
    int q = 0;

    int* strany = new int[3];

public:
    
    PTrojuhelnik(int koef_p, int koef_q) 
    {
        p = koef_p;
        q = koef_q;
    }

    void pocitejA()
    {
        strany[0] = (q * q - p * p);
    }

    void pocitejB()
    {
        strany[1] = (2 * p * q);
    }

    void pocitejC()
    {
        strany[2] = (q * q + p * p);
    }

    bool platiPythagorovaVeta() 
    {
        auto a = strany[0];
        auto b = strany[1];
        auto c = strany[2];

        if (c == sqrt(a * a + b * b))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void vypisVysledky() 
    {
        std::cout << "Zadane cislo p = " << p << "\nZadane cislo q = " << q << "\n";
        std::cout << "Strany trojuhelnika jsou:\n";
        std::cout << "odvesna a = " << strany[0] << "\nodvesna b = " << strany[1] << "\nprepona c = " << strany[2] << "\n";
        std::cout << "Pro trojuhelnik " << (platiPythagorovaVeta() ? "plati" : "neplati") << " Pythagorova veta.\n";

    }


};

int main()
{

    int p = nacti_hodnotu("Zadej cislo p: ", 0, 10000);
    int q = nacti_hodnotu("Zadej cislo q (vetsi nez predchozi p): ", p, 10000);

    //int* koeficienty_p_q = new int[2];
    //
    //int* strany = new int[3];

    //strany[0] = pocitejA(p, q);
    //strany[1] = pocitejB(p, q);
    //strany[2] = pocitejC(p, q);

    //koeficienty_p_q[0] = p;
    //koeficienty_p_q[1] = q;
    //
    //bool overeni = platiPythagorovaVeta(strany[0], strany[1], strany[2]);

    //vypisVysledky(koeficienty_p_q, strany, overeni);

    PTrojuhelnik trojuhelnik(p, q);
    trojuhelnik.pocitejA();
    trojuhelnik.pocitejB();
    trojuhelnik.pocitejC();
    trojuhelnik.vypisVysledky();


}
