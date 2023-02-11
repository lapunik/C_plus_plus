#include <iostream>
#include <functional>

template <typename T>
class FunctionPointer {
public:
    FunctionPointer(T&& f) : func(std::forward<T>(f)) {}

    std::function<T> func;
};

auto soucet(int x, double y)
{
    return x * y;
}

auto pozdrav(std::string s)
{
    return s + "Hello";
}


int main() {
    FunctionPointer<decltype(soucet)> pointer(soucet);
    auto x = 10;
    auto y = 5;
    std::cout << "Soucet " << x << " + " << y << " = " << pointer.func(5, 2) << std::endl;

    FunctionPointer<decltype(pozdrav)> pointer2(pozdrav);
    std::cout << pointer2.func("Ahoj = ") << std::endl;
}
