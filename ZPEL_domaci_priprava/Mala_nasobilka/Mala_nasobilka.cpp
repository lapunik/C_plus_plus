#include <iostream>

int main()
{
    // 1. Základ
    
    //int cislo = 0;

    //std::cout << "Zadej hodnotu od 1 do 9: ";
    //std::cin >> cislo;

    //std::cout << "\nMala nasobilka:\n\n";
    //for (int i = 1; i <= 10; i++)
    //{
    //    std::cout << i * cislo << "\n";
    //}
    

    // 2. Ošetření hranic

    //int cislo = 0;

    //std::cout << "Zadej hodnotu od 1 do 9: ";

    //std::cin >> cislo;

    //if ((cislo < 10) && (cislo > 0))
    //{
    //    std::cout << "\nMala nasobilka:\n\n";

    //    for (int i = 1; i <= 10; i++)
    //    {
    //        std::cout << i * cislo << "\n";
    //    }
    //}
    //else 
    //{
    //    std::cout << "Pocitani neni tvoje silna stranka.\n";
    //}


    // 3. Ošetření hranic s while
    
    //int cislo = 0;

    //std::cout << "Zadej hodnotu od 1 do 9: ";

    //std::cin >> cislo;

    //while ((cislo > 9) || (cislo < 1))
    //{
    //    std::cout << "Respektuj povoleny rozsah hodnot!\nZadej hodnotu od 1 do 9: ";
    //    std::cin >> cislo;
    //}

    //std::cout << "\nMala nasobilka:\n\n";

    //for (int i = 1; i <= 10; i++)
    //{
    //    std::cout << i * cislo << "\n";
    //}
    
    // 4. Dotaz na opakování výpočtu

    int cislo = 0;
    std::string odpoved = "ano";

    while (true)
    {
        std::cout << "Zadej hodnotu od 1 do 9: ";

        std::cin >> cislo;

        while ((cislo > 9) || (cislo < 1))
        {
            std::cout << "Respektuj povoleny rozsah hodnot!\nZadej hodnotu od 1 do 9: ";
            std::cin >> cislo;
        }

        std::cout << "\nMala nasobilka:\n";

        for (int i = 1; i <= 10; i++)
        {
            std::cout << i * cislo << "\n";
        }

        std::cout << "\nChces program ukoncit? (ano/ne): ";
        std::cin >> odpoved;

        while (!((odpoved == "ano") || (odpoved == "ne")))
        {
            std::cout << "Zadej bud \"ano\" nebo \"ne\"! \nChces program ukoncit? (ano / ne) : ";
            std::cin >> odpoved;
        }

        if (odpoved == "ano")
        {
            break;
        }
        else
        {
            std::cout << "\n";
        }

    }
    

}
