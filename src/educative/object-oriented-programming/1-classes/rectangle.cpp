#include <iostream>
#include "rectangle.h"
using namespace std;

float rectangle::perimeter()
{
    return (length * 2 + height * 2);
}

float rectangle::area()
{
    return (length * height);
}

int main()
{
    rectangle rec1(2, 10);
    cout << "Perimeter: " << rec1.perimeter() << endl;
    cout << "Area: " << rec1.area() << endl;
}