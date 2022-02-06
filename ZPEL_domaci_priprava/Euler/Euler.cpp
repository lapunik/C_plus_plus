#include <iostream>
#include <string>
#include <limits>
#include <cmath>

double nacti_hodnotu(std::string vyzva, double min, double max)
{
    while (!std::cin.eof())
    {
        std::cout << vyzva << '\n';

        double hodnota = 0;
        std::cin >> hodnota;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (hodnota > min && hodnota <= max)
            return hodnota;
    }

    return 0;
}

int nacti_hodnotu(std::string vyzva, int min, int max)
{
    while (!std::cin.eof())
    {
        std::cout << vyzva << '\n';

        int hodnota = 0;
        std::cin >> hodnota;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (hodnota > min && hodnota <= max)
            return hodnota;
    }

    return 0;
}

int faktorial(int n)
{
    int vysledek = 1;

    for (int i = 1; i <= n; i++)
    {
        vysledek *= i;
    }
    return vysledek;
}

double vypocetCykly(int n)
{
    double eu = 0;

    for (int i = 0; i <= n; i++) 
    {
        eu += (1.0 / (static_cast<double>(faktorial(i))));
    }

    return eu;
}

double vypocetPresnost(double e)
{
    double eu = 0;
    double eu_old = 0;
    int n = 0;

    while (true)
    {
        eu += (1.0 / (static_cast<double>(faktorial(n))));
        n++;

        if (abs(eu - eu_old) <= e)
        {
            return eu;
        }

        eu_old = eu;
    }
    return eu;
}

void kontrola(double hodnoty[2]) 
{
    for (int i = 0; i < 2; i++) 
    {
        hodnoty[i] = 2.71828182845904523536 - hodnoty[i];
    }
}

void vypisVysledky(int n, double e, double cykly, double presnsot, double rozdily[2]) 
{
    std::cout << "Eulerovo cislo spoctene pomoci " << n << " iteraci je e = " << cykly << "\n";
    std::cout << "rozdil oproti referencni hodnote je " << rozdily[0]<<"\n";
    std::cout << "Eulerovo cislo spoctene s presnosti " << e << " je e = " << presnsot << "\n";
    std::cout << "rozdil oproti referencni hodnote je " << rozdily[1] << "\n";

}

class Euler
{
private:

    int n = 0;
    double e = 0.0;
    double euler_cykly = 0.0;
    double euler_presnost = 0.0;
    double rozdily[2] = { 0.0,0.0 };

public:

    Euler(int cykly, double presnost)
    {
        n = cykly;
        e = presnost;
    }

    int faktorial(int hodnota)
    {
        int vysledek = 1;

        for (int i = 1; i <= hodnota; i++)
        {
            vysledek *= i;
        }
        return vysledek;
    }

    void vypocetCykly()
    {
        double eu = 0;

        for (int i = 0; i <= n; i++)
        {
            eu += (1.0 / (static_cast<double>(faktorial(i))));
        }

        euler_cykly = eu;

    }

    void vypocetPresnost()
    {
        double eu = 0;
        double eu_old = 0;
        int cykl = 0;

        while (true)
        {
            eu += (1.0 / (static_cast<double>(faktorial(cykl))));
            cykl++;

            if (fabs(eu - eu_old) <= e)
            {
                euler_presnost = eu;
                return;
            }

            eu_old = eu;
        }

    }

    void kontrola()
    {
        rozdily[0] = 2.71828182845904523536 - euler_cykly;
        rozdily[1] = 2.71828182845904523536 - euler_presnost;
    }

    void vypisVysledky()
    {
        std::cout << "Eulerovo cislo spoctene pomoci " << n << " iteraci je e = " << euler_cykly << "\n";
        std::cout << "rozdil oproti referencni hodnote je " << rozdily[0] << "\n";
        std::cout << "Eulerovo cislo spoctene s presnosti " << e << " je e = " << euler_presnost << "\n";
        std::cout << "rozdil oproti referencni hodnote je " << rozdily[1] << "\n";

    }


};

int main()
{
    int n = 8;
    double e = 1e-6;

    int n = nacti_hodnotu("Zadej pocet cyklu: ", 0, 10);
    double e = nacti_hodnotu("Zadej presnost vypoctu: ", 1e-10, 1.0);

    //double cykly = vypocetCykly(n);
    //double presnost = vypocetPresnost(e);
    //double hodnoty[2] = {cykly,presnost};
    //kontrola(hodnoty);
    //std::cout.precision(17);
    //vypisVysledky(n,e,cykly,presnost,hodnoty);

    Euler euler(n, e);
    euler.vypocetCykly();
    euler.vypocetPresnost();
    euler.kontrola();
    euler.vypisVysledky();

}
