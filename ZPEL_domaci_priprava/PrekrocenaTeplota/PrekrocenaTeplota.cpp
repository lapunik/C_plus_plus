#include <iostream>

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


int main()
{

}