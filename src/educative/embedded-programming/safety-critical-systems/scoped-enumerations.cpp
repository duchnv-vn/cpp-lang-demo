#include <iostream>
using namespace std;

enum
{
    red,
    green = 2,
    blue
};

enum struct NewEnum
{
    one = 1,
    ten = 10,
    hundred = 100,
    thousand = 1000
};

enum struct Color2 : char
{
    red2 = 100,
    blue2,
    green2
};

int main()
{
    cout << "red: " << red << endl;
    cout << "green: " << green << endl;
    cout << "blue: " << blue << endl;

    cout << "one * 2: " << (2 * static_cast<int>(NewEnum::one)) << endl; // Scoped enumeration NewEnum::one

    cout << "blue2: " << static_cast<char>(Color2::blue2) << endl;
}