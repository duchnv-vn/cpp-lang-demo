// ***************************************
// DATA TYPES & INPUT
#include <iostream>
using namespace std;

int main(void)
{
    /*
    Premitive data types
     */
    if (0)
    {
        double doubleNum = 97e7;
        char char1 = 'C';
        bool isTrue = true;
    }

    /*
    Data type modifiers
     */
    if (0)
    {
        long long int number = 2147483649;
        cout << number << endl;
    }

    /*
    Type casting
     */
    if (1)
    {
        int int_value = 13.9;
        cout << int_value << endl; // 13

        int int_value_2 = 13.1;
        cout << int_value_2 << endl; // 13

        char character = 'A';
        int ASCII;
        ASCII = (int)character;
        cout << ASCII << endl; // 65
    }
}