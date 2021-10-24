#include <iostream>

using namespace std;

int main()
{
    /* Kontrola věku:

    int hodnota = 0;

    cout << "Zadej svuj vek: ";
    cin >> hodnota;

    if (hodnota < 18)
    {
        cout << "Pristup odepren.";
    }
    else
    {
        cout <<  "Pristup povolen.";
    }

    //*/

    /* Nezadavej urcotou hodnotu:

    int hodnota = 0;

    while (hodnota == 0) 
    {
        cout << "Zadej cokoliv jinyho nez nulu: ";
        cin >> hodnota;
    }

    cout << "Dekuji";

    //*/

    /*

    //for (int i = 0; i < 5; i++) // od nuly do čtyř
    //for (int i = 1; i <= 5; i++) // od nuly do čtyř
    //for (int i = 10; i <= 15; i++) // od nuly do čtyř 
    //for (int i = 5; i > 0; i--) // od nuly do čtyř
    //for (int i = 0; i < 10; i += 2 ) // od nuly do osmi po dvou
    for (int i = 1; i < 100; i *= 2) // od nuly do 64 po mocninach
    {
        // cout << "Ahoj\n";
        cout << "Iterace: " << i << "\n";
    }

    //*/

    /* Přerušení cyklů:

    int hodnota = 0;

    while (true)
    {
        cout << "Zadej hodnotu jedna: ";
        cin >> hodnota;

        if (hodnota == 1)
        {
             continue; // přeskoč současnou iteraci
            // break; // přeskoč všechny zbylé iterace

        }

        cout << "Tady se vykonava dalsi program\n";
    }

    cout << "Konec programu \n";

    //*/


    //* // dotaz na ukončení programu

    bool pokracovat = true;
    string text = "???";

    while (pokracovat)
    {
        cout << "Chces ukoncit program? (ano/ne): ";
        cin >> text;
        if (text == "ano")
        {
            break;
        }
        else if (text == "ne")
        {
            cout << "Program bude pokracovat dale.\n";
        }
        else
        {
            cout << "Zadej pouze hodnotu \"ano\" nebo \"ne\".\n";
        }
            
    }

    cout << "Dekuji";

    //*/

 


}
