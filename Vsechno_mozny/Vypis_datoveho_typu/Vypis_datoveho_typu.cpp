#include <iostream>

template <typename Func>
void result_type(Func func)
{
    using result_type = decltype(func());
    std::cout << typeid(result_type).name() << std::endl; // vypsání typu na obrazovku
}

auto foo()
{
    return 0;
}

auto doo()
{
    return "Ahoj";
}

int main()
{
    result_type(foo);
    result_type(doo);

}