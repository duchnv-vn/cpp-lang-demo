#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
struct Add
{
    static_assert(is_arithmetic_v<T>, " T must be an arithmetic type");
};

template <typename T>
T gcd(T a, T b)
{
    static_assert(is_integral_v<T>, " T must be an integral type");

    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    if (false)
    {
        static_assert(sizeof(void *) >= 8, "64-bit addressing is required for this program");

        auto addInt = Add<int>();
        auto addDouble = Add<double>();
        auto addChar = Add<char>();
        // auto addString = Add<string>(); // Compile error
    }

    if (true)
    {
        auto result1 = gcd(99.0, 63.0);
        cout << "Result 1: " << result1 << endl;

        // auto result2 = gcd("100", "10"); // Compile error
    }
}