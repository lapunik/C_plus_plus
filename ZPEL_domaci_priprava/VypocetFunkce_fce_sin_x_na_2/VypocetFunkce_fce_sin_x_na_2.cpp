#include <iostream>
#include <string>
#include <limits>
#include <cmath>

//int zaporne(double* hodnoty, int pocet_hodnot)
//{
//    int z = 0;
//
//    for (int i = 0; i < pocet_hodnot; i++)
//    {
//        if (hodnoty[i] < 0)
//        {
//            z++;
//        }
//    }
//
//    return z;
//}
//
//int kladne(double* hodnoty, int pocet_hodnot)
//{
//    int k = 0;
//
//    for (int i = 0;i<pocet_hodnot;i++) 
//    {
//        if(hodnoty[i]>0)
//        {
//            k++;
//        }
//    }
//
//    return k;
//}
//
//void vypisHodnot(double* hodnoty, double a, double b, double k)
//{
//    std::cout << "Dolni mez: " << a << "\n";
//    std::cout << "Horni mez: " << b << "\n";
//    std::cout << "Krok: " << k << "\n";
//
//    double x = 0.0;
//
//    int pocet_hodnot = (static_cast<int>((b - a) / k) + 1);
//
//    for (int i = 0; i < pocet_hodnot; i++)
//    {
//        x = a + static_cast<double>(i) * k;
//
//        std::cout << "x: " << x << "   y: " << hodnoty[i] << "\n";
//    }
//
//    //std::cout << "Kladnych cisel: " << kladne(hodnoty, pocet_hodnot) << "\nZapornych cisel: " << zaporne(hodnoty, pocet_hodnot) << "\n";
//
//}
//
//void vykresleniHodnot(double* hodnoty, int pocet_hodnot)
//{
//    
//    for (int i = 0; i < pocet_hodnot; i++)
//    {
//        if (hodnoty[i]<-0.3) 
//        {
//            std::cout << "o\n";
//        }
//        else if (hodnoty[i] > 0.3)
//        {
//            std::cout << "ooo\n";
//        }
//        else 
//        {
//            std::cout << "oo\n";
//        }
//        
//    }
//
//}
//
//void vypocetHodnot(double a, double b, double k, double* hodnoty)
//{
//    double x = 0.0;
//    for (int i = 0; i < (static_cast<int>((b - a) / k) + 1); i++)
//    {
//        x = a + static_cast<double>(i) * k;
//        hodnoty[i] = sin(pow(x, 2));
//    }
//
//}

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

class Funkce
{
private:

    double a = 0;
    double b = 0;
    double k = 0;

    double* hodnoty;

public:

    Funkce(double dolniMez, double horniMez, double krok)
    {
        a = dolniMez;
        b = horniMez;
        k = krok;
        hodnoty = new double[(static_cast<int>((b - a) / k) + 1)];
    }

    int zaporne()
    {
        int z = 0;

        for (int i = 0; i < (static_cast<int>((b - a) / k) + 1); i++)
        {
            if (hodnoty[i] < 0)
            {
                z++;
            }
        }

        return z;
    }

    int kladne()
    {
        int kl = 0;

        for (int i = 0; i < (static_cast<int>((b - a) / k) + 1); i++)
        {
            if (hodnoty[i] > 0)
            {
                kl++;
            }
        }

        return kl;
    }

    void vypisHodnot()
    {
        std::cout << "Dolni mez: " << a << "\n";
        std::cout << "Horni mez: " << b << "\n";
        std::cout << "Krok: " << k << "\n";

        double x = 0.0;

        int pocet_hodnot = (static_cast<int>((b - a) / k) + 1);

        for (int i = 0; i < pocet_hodnot; i++)
        {
            x = a + static_cast<double>(i) * k;

            std::cout << "x: " << x << "   y: " << hodnoty[i] << "\n";
        }

        std::cout << "Kladnych cisel: " << kladne() << "\nZapornych cisel: " << zaporne() << "\n";

    }

    void vykresleniHodnot()
    {

        for (int i = 0; i < (static_cast<int>((b - a) / k) + 1); i++)
        {
            if (hodnoty[i] < -0.3)
            {
                std::cout << "o\n";
            }
            else if (hodnoty[i] > 0.3)
            {
                std::cout << "ooo\n";
            }
            else
            {
                std::cout << "oo\n";
            }

        }

    }

    void vypocetHodnot()
    {
        double x = 0.0;
        for (int i = 0; i < (static_cast<int>((b - a) / k) + 1); i++)
        {
            x = a + static_cast<double>(i) * k;
            hodnoty[i] = sin(pow(x, 2));
        }

    }

};

int main()
{
    double a = 1.0;
    double b = 6.5;
    double k = 0.5;

    //int pocet_hodnot = (static_cast<int>((b - a) / k) + 1);
    //
    //double* hodnoty = new double[pocet_hodnot];
    //
    //vypocetHodnot(a, b, k, hodnoty);

    //vypisHodnot(hodnoty, a, b, k);

    //vykresleniHodnot(hodnoty, pocet_hodnot);

    Funkce f(a, b, k);
    f.vypocetHodnot();
    f.vypisHodnot();
    f.vykresleniHodnot();


}