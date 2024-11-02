// ***************************************
// DATA TYPES & INPUT
#include <iostream>
using namespace std;

int main() {
    /*
    *  Primitive data types
     */
    if (false) {
        double doubleNum = 97e7;
        char char1 = 'C';
        bool isTrue = true;
    }

    /*
    * Data type modifiers
     */
    if (false) {
        long long int number = 2147483649;
        cout << number << endl;
    }

    /*
    * Type casting
     */
    if (false) {
        int int_value = 13.9;
        cout << int_value << endl; // 13

        int int_value_2 = 13.1;
        cout << int_value_2 << endl; // 13

        char character = 'A';
        int ASCII;
        ASCII = (int) character;
        cout << ASCII << endl; // 65
    }

    /*
     * String & Escape Sequences
     */
    if (false) {
        const string text = "Hello World!";
        cout << text << endl;
    }

    /*
     * User input
     */
    if (false) {
        int inputValue;

        cout << "Enter an integer: " << endl;
        cin >> inputValue;
        cout << "You have entered: " << inputValue << endl;
    }

    if (false) {
        double double_value = 70.986;
        int int_value = (int) double_value;
        cout << int_value << endl;
    }
}
