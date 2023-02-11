#include <iostream>

class Song 
{
public:
    std::string nazev;
    std::string intepret;

private:

};


void funkce_s_pointrem() 
{
    int* a = new int;

    // nejaky kod


    delete a;

}

void funkce_s_chytrym_pointrem()
{
    //std::unique_ptr<int> a (new int);

    std::shared_ptr<int> a(new int);

    // nejaky kod

    //std::unique_ptr<int> dalsi_a = a; // nelze
    std::shared_ptr<int> dalsi_a = a; 

}

int main()
{

}
