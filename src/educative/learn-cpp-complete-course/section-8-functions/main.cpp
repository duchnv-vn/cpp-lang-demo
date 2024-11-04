#include <iostream>
#include <cmath>
using namespace std;

/*
 * Default parameters
 */
int multiply(int a, int b = 1)
{
    return a * b;
}

void powByReference(int &a, int b)
{
    a = pow(a, b);
}

string digit_text(int number)
{
    if (number > 5 || number < 0)
        return "invalid number";

    const string digit_texts[6] = {"zero", "one", "two", "three", "four", "five"};
    return digit_texts[number];
}

void minimum(int &number1, int &number2)
{
    if (number1 >= number2)
        number2 = -1;

    else if (number2 >= number1)
        number1 = -1;
    else
    {
        number1 = -1;
        number2 = -1;
    }
}

double test(double number1, char operate, double number2)
{

    switch (operate)
    {
    case '+':
        return number1 + number2;

    case '-':
        return number1 - number2;

    case '*':
        return number1 * number2;

    case '/':
        return number1 / number2;

    default:
        return -1;
    }
}

int main()
{
    if (false)
    {
        cout << multiply(1, 2) << endl;
        cout << multiply(3) << endl;

        int num1 = 10;
        int num2 = 2;
        powByReference(num1, num2);
        cout << num1 << endl; // 100
    }

    /*
     * Convert Digits from 0 to 5 into Text
     */
    if (false)
    {
        int number = 5;
        string numStr = digit_text(number);
        cout << numStr << endl;
    }

    /*
     * Set the Smallest Number to -1
     */
    if (false)
    {
        int number1 = -31;
        int number2 = -65;
        minimum(number1, number2);
        cout << number1 << endl;
        cout << number2 << endl;
    }

    /*
     * Design a Calculator
     */
    if (true)
    {
        cout << test(7.9, '+', 6.2) << endl;
        cout << test(7.9, '-', 6.2) << endl;
        cout << test(7.9, '*', 6.2) << endl;
        cout << test(7.9, '/', 6.2) << endl;
        cout << test(7.9, '=', 6.2) << endl;
    }
}
