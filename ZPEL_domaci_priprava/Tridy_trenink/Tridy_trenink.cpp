#include <iostream>

using namespace std;

class Kvadr
{
public:

    enum material 
    {
        drevo = static_cast<int>('x'),
        zelezo = static_cast<int>('*'),
        kamen = static_cast<int>('o'),
        guma = static_cast<int>('/'),
        keramika = static_cast<int>('+'),
    };

    enum pohled
    {
        zepredu,
        z_prava,
        shora,
    };

    Kvadr() 
    {
    
    }

    Kvadr(int aa, int bb, int cc)
    {
        a = aa;
        b = bb;
        c = cc;
    }



    Kvadr(int aa, int bb, int cc, Kvadr::material m)
    {
        a = aa;
        b = bb;
        c = cc;
        mat = m;
    }

    Kvadr(Kvadr::material m)
    {

        mat = m;
    }

    void Zmen_rozmery(int aa, int bb, int cc)
    {

        a = aa;
        b = bb;
        c = cc;

        Objem();
    }

    void Zmen_material(material m)
    {
        mat = m;
    }

    void Objem()
    {
        objem =  a * b * c;
    }

    int Vrat_objem() 
    {
        return objem;
    }

    int Povrch()
    {
        return 2 * (a * b + b * c + c * a);
    }

    void Vykresli_se_3D()
    {
        char m = static_cast<int>(mat);

        for (int y = 0; y < b + c - 1; y++)
        {
            for (int x = 0; x <= ((2 * (a - 1)) + (c - 1)); x++)
            {
                // vykresleni svislych car
                if ((y > c - 1) && ((x == 0) || (x == (a - 1) * 2)))
                {
                    cout << m;
                }
                else if ((y <= b - 1) && (x == ((2 * (a - 1)) + (c - 1))))
                {
                    cout << m;
                }
                // vyskresleni sikmych car
                else if (((y > 0) && (y < c - 1)) || ((y > 0)&&(x > (a - 1) * 2)))
                {
                    if (((c - 1) - x) == y)
                    {
                        cout << m;
                    }
                    else if (((c - 1) - x + (a - 1)*2) == y)
                    {
                        cout << m;
                    }
                    else if (((c - 1) - x + (a - 1) * 2) == y-(b-1))
                    {
                        cout << m;
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                // vykresleni vodorovnych car
                else if ((y == 0) && (x >= c - 1))
                {
                    if (x % 2 ==(c%2==0?1:0))
                    {
                        cout << m;
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                else if (((y == c - 1) || (y == b + c - 2)) && (x <= (a - 1) * 2))
                {
                    if (x % 2 == 0)
                    {
                        cout << m;
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                else
                {
                    cout << " ";
                }
            }

            cout << "\n";

        }

    }

    void Vykresli_se_2D(pohled p) 
    {
        char m = static_cast<int>(mat);

        int a;
        int b; 

        switch (p)
        {
        case Kvadr::zepredu:
            a = this->a;
            b = this->b;
            break;
        case Kvadr::z_prava:
            a = this->c;
            b = this->b;
            break;
        case Kvadr::shora:
            a = this->a;
            b = this->c;
            break;
        default:
            break;
        }
        cout << "\n";
        for (int y = 0; y < b; y++)
        {
            for (int x = 0; x <= (a-1)*2; x++)
            {
                if ((x == 0) || (x == (a - 1) * 2))
                {
                    cout << m;

                }
                else if ((y == 0) || (y == b - 1))
                {
                    if (x % 2 == 0)
                    {
                        cout << m;
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                else 
                {
                    cout << " ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }

private:

    int a = 1, b = 1, c = 2;
    int objem;
    material mat = drevo;
};


int soucet(int a, int b) 
{
    return a + b;
}

int main()
{


    int delka = 9, sirka = 4, vyska = 6;
    //cout << "Zadej rozmery kvadru: " << "\n";
    //cin >> delka >> sirka >> vyska;

    Kvadr k(delka, sirka, vyska, Kvadr::drevo);
    Kvadr k1(delka, sirka, vyska);

    int a =  5;
    int a = 5;


    Kvadr k2(Kvadr::drevo);


    k.Objem();

    cout << k.Vrat_objem() << "\n";

    k.Zmen_rozmery(15, 4, 6);
   
    cout << k.Vrat_objem() << "\n";
    
   




    //cout << "Objem kvadru: " << k.Objem() << "\n";
    //cout << "Povrch kvadru: " << k.Povrch() << "\n\n";
    //k.Vykresli_se_2D(Kvadr::zepredu);
    //k.Vykresli_se_2D(Kvadr::z_prava);
    //k.Vykresli_se_2D(Kvadr::shora);
    //k.Vykresli_se_3D();

    //Kvadr k2; // ukázat příkald se stringem.

    //cout << "Objem kvadru: " << k2.Objem() << "\n";
    //cout << "Povrch kvadru: " << k2.Povrch() << "\n\n";
    //k2.Vykresli_se_2D(Kvadr::zepredu);
    //k2.Vykresli_se_2D(Kvadr::z_prava);
    //k2.Vykresli_se_2D(Kvadr::shora);
    //k2.Vykresli_se_3D();
}