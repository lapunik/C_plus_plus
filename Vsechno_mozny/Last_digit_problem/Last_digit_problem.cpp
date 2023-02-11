#include <list>
#include <iostream>

using namespace std;

int last_digit(const std::list<int>& nums) {

    if (nums.empty())
    {
        return 1;
    }

    long int result = nums.back();
    long int temp_result = 1;
    long int last_digit;

    for (auto it = std::prev(std::prev(nums.end())); it != nums.begin(); --it)
    {
        last_digit = *it % 10;

        //if (!last_digit)
        //{
        //    result = 1;
        //    continue;
        //}

        for (int i = 0; i < result; ++i)
        {
            temp_result *= last_digit;
            temp_result %= 10;
        }

        result = temp_result;
        temp_result = 1;
    }

    return (int)(result % 10);
}

int main()
{
    const std::list<int> a{ 7,6,21 };

    std::cout << last_digit(a);
}