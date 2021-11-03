#include <iostream>

using namespace std;

int main() 
{
    int citatel;
    int jmenovatel;
    double vysledek;

    cout << "Zadej citatel: ";
    cin >> citatel;
    cout << "Zadej jmenovatel: ";
    cin >> jmenovatel;

    //vysledek = citatel / jmenovatel;
    //cout << "Vysledek deleni: " << vysledek;
    
    //*

    try 
    {
        if (jmenovatel == 0) 
        {
            //throw "";
            throw "Nelze delit nulou";
        }

        vysledek = citatel / jmenovatel;

        if (vysledek > 5) 
        {
            //throw "";
            throw "Vysledek je vetsi nez 5!";
        }

        cout << "Vysledek deleni: " << vysledek;

    }
    //catch (...)
    catch(const char* text)
    {
        //cout << "Vyjimka";
        cout << text;
    }

    //*/

}