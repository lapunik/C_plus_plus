#include <iostream>

using namespace std;

double Deleno(int a, int b) 
{
    /*
    if (b == 0)
    {
        // A tady mám dělat co?
        return -1.0;
    }
    //*/

    /*
    if (b == 0)
    {
        throw "Nelze delit nulou";
    }
    //*/

    return a / b;
}

int main() 
{
    int citatel;
    int jmenovatel;
    double vysledek;

    cout << "Zadej citatel: ";
    cin >> citatel;
    cout << "Zadej jmenovatel: ";
    cin >> jmenovatel;

    vysledek = citatel / jmenovatel;
    cout << "Vysledek deleni: " << vysledek;
    
    /*
    if (jmenovatel == 0)
    {
        cout << "Nelze delit nulou";
    }
    else 
    {
        vysledek = citatel / jmenovatel;
        cout << "Vysledek deleni: " << vysledek;
    }
    //*/

    /*
    try 
    {
        if (jmenovatel == 0) 
        {
            throw "";
            //throw "Nelze delit nulou";
        }

        vysledek = citatel / jmenovatel;

        //if (vysledek > 5) 
        //{
        //    throw "Vysledek je vetsi nez 5!";
        //}

        cout << "Vysledek deleni: " << vysledek;

    }
    catch (...)
    //catch(const char* text)
    {
        cout << "Vyjimka";
        //cout << text;

    }
    //*/

    //vysledek = Deleno(citatel, jmenovatel);
   
    /*
    vysledek = Deleno(citatel, jmenovatel);
    if (vysledek == -1.0)
    {
        cout << "Nelze delit nulou!";

    }
    else
    {
        cout << "Vysledek deleni: " << vysledek;
    }
    //*/

    /*

    try
    {
        vysledek = Deleno(citatel,jmenovatel);
        cout << "Vysledek deleni: " << vysledek;
    }
    catch(const char* text)
    {
        cout << text;
    }

    //*/

}