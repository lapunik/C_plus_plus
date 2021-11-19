#include <iostream>

using namespace std;

int main()
{
    //*
    int pole[3][3];

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {

            pole[i][j] = (3*j)+i+1;

        }

    }


    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {

           cout << pole[i][j];

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
