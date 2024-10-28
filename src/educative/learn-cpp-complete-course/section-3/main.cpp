// ***************************************
// VARIABLES & CONSTANTS
#include <iostream>
using namespace std;

int main(void)
{
    int num = 10;
    const float floatNum = 10.5;

    int var;
    var = 5000;
    cout << "var = " << var << endl;

    var = 1000;
    cout << "var = " << var;

    int var1 = 1;
    int var2 = 2;

    int temp = var1;
    var1 = var2;
    var2 = temp;
}