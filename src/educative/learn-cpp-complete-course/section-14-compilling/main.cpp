#include <iostream>
using namespace std;

int main()
{
    int x = 9, y = 20;
    x = y % x;
    y = x << 1;
    cout << (y = x | 8) << endl;
    cout << (x = x + y) << endl;
}