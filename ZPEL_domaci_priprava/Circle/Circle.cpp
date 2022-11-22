#include <iostream>

int main()
{
    const char ZNAK = '*';
    const int size = 5;

    int x = 0;
    int y = 0;

    for (int i = 0; i < (2 * size + 1); i++)
    {
        x = size - i;

        for (int j = 0; j < (2 * size + 1); j++)
        {
            y = size - j;

            if ((x * x) + (y * y) == (size * size))
            {
                std::cout << ZNAK;
            }
            else 
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

}
