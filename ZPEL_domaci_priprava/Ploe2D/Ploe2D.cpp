#include <iostream>

using namespace std;

void nahrad_za_nuly(int pole[][3])
{
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (pole[j][i] < 0) 
            {
                pole[j][i] = 0;
            }
        }
    }
}


int main()
{
    //*
    int pole[3][3] = { {1,5,-9},{0,-7,7},{11,-5,8} };



    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {

           cout << pole[i][j];
           cout << "\t";

        }

        cout << "\n";

    }

    cout << "\n";
    
    nahrad_za_nuly(pole);

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {

            cout << pole[i][j];
            cout << "\t";

        }

        cout << "\n";

    }

    //*/

    /*

    int** dvourozmerne_pole = new int* [3];

    for (int i = 0; i < 3; i++)
    {
        dvourozmerne_pole[i] = new int[3];
    }

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            dvourozmerne_pole[i][j] = ((3 * j) + (i + 1));
        }
    }

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << dvourozmerne_pole[i][j];
        }
        cout << "\n";
    }

    //*/

}
