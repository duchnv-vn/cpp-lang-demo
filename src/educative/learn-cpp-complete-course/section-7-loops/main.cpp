#include <iostream>
using namespace std;

int main()
{
    /*
     * Calculate the Power of a Number
     */
    if (false)
    {
        int base = 2;
        int exponent = 3;
        int result = 1;

        for (int i = 1; i <= exponent; i++)
        {
            result *= base;
        }
    }

    /*
     * Find out if the Given Number is Prime
     */
    if (false)
    {
        int number = 31;
        bool isPrime = true;

        if (number <= 1)
        {
            isPrime = false;
        }
        else
        {
            for (int i = 2; i < number / 2; i++)
            {
                if (number % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
        }

        cout << (isPrime ? "prime" : "not prime") << endl;
    }

    /*
     * Convert Decimal Number to Binary - Solution 1
     */
    if (false)
    {
        int decimal = 10;
        string binary;

        do
        {
            const int remainder = decimal % 2;
            decimal /= 2;
            binary = std::to_string(remainder) + binary;
        } while (decimal > 0);

        cout << "Binary: " << binary << endl;
    }

    /*
     * Convert Decimal Number to Binary - Solution 2
     */
    if (false)
    {
        int decimal = 10;
        int binary = 0;
        int remainder, product = 1;

        while (decimal != 0)
        {
            remainder = decimal % 2;
            binary += remainder * product;
            decimal = decimal / 2;
            product *= 10;
        }

        cout << "Binary: " << binary << endl;
    }

    /*
     * Find out if the Given Number is a Palindrome
     */
    if (true)
    {
        int number = 212;
        int numLength = 0;

        int tempNum = number;
        while (tempNum != 0)
        {
            numLength++;
            tempNum /= 10;
        }

        int numArr[numLength] = {0};

        for (int i = 0; i < numLength; i++)
        {
            int tempNum = number;
            for (int j = 0; j < i; j++)
                tempNum /= 10;

            numArr[numLength - (i + 1)] = tempNum % 10;
        }

        bool isPalindrome = true;
        int limit = numLength / 2;
        for (int i = 0; i < limit; i++)
        {
            int headNum = numArr[i];
            int lastNum = numArr[numLength - (i + 1)];

            if (headNum != lastNum)
            {
                isPalindrome = false;
                break;
            }
        }

        cout << (isPalindrome ? "is palindrome" : "not a palindrome") << endl;
    }
}
