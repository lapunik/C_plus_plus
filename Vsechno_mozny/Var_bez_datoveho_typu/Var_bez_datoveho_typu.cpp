#include <iostream>
#include <any>
#include <functional>

int main()
{
    std::any var = 5;


    std::cout << "Type: " << var.type().name() << std::endl;
    std::cout << "Value: " << std::any_cast<int>(var) << std::endl;

    var = 'a';

    std::cout << "Type: " << var.type().name() << std::endl;
    std::cout << "Value: " << std::any_cast<char>(var) << std::endl;

    return 0;
}