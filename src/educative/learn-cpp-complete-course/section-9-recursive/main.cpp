#include <iostream>
using namespace std;

int calculateFactorialNumber(int number)
{
    if (number < 0)
        return -1;

    if (number == 1 || number == 0)
        return 1;

    return number * calculateFactorialNumber(number - 1);
}

int power(int base, int exponent)
{
    if (exponent == 0)
        return 1;

    return base * power(base, exponent - 1);
}

int count_digits(int number)
{
    int remainer = number / 10;

    if (remainer == 0)
        return 1;

    return 1 + count_digits(remainer);
}

int fibonacci(int n)
{
    if (n < 0)
        return -1;

    if (n == 0)
        return 0;

    if (n <= 2)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    /*
     * Calculating the Factorial of a Number
     */
    if (false)
    {
        cout << "10! = " << calculateFactorialNumber(10) << endl;

        int fact = 1;
        for (int counter = 1; counter <= 10; counter++)
            fact *= counter;
        cout << "10! = " << fact << endl;
    }

    /*
     * Calculate the Power of a Number Recursively
     */
    if (false)
    {
        cout << "2^0 = " << power(2, 0) << endl;
        cout << "2^1 = " << power(2, 1) << endl;
        cout << "2^3 = " << power(2, 3) << endl;
        cout << "2^99 = " << power(2, 19) << endl;
    }

    /*
     * Count the Digits in a Number Using Recursion
     */
    if (false)
    {
        cout << "Digit number of 2436: " << count_digits(2436) << endl;
        cout << "Digit number of 1: " << count_digits(1) << endl;
        cout << "Digit number of -1234: " << count_digits(-1234) << endl;
    }

    /*
     * Calculate the nth Fibonacci Number using Recursion
     */
    if (true)
    {
        cout << "fibonacci number of 0: " << fibonacci(0) << endl;
        cout << "fibonacci number of 1: " << fibonacci(1) << endl;
        cout << "fibonacci number of 2: " << fibonacci(2) << endl;
        cout << "fibonacci number of 6: " << fibonacci(6) << endl;
    }
}