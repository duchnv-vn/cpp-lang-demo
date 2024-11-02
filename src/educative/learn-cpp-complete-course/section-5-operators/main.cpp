#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    /*
     * Introduction to operators
     */
    if (false)
    {
        char operand1 = 'n';
        char operand2 = 'C';
        cout << "Division = " << operand1 / operand2 << endl;
        cout << "Modulus = " << operand1 % operand2 << endl;
    }

    /*
     * Find the Previous Alphabet
     */
    if (false)
    {
        char character = 'B';
        char character_before = ((int)character) - 1;
        cout << "Character = " << character << endl;
        cout << "Before character = " << character_before << endl;
    }

    /*
     * Calculate Hours, Minutes, and Seconds
     */
    if (false)
    {
        int total_seconds = 3870;
        int hours, minutes, seconds;

        // Solution 1
        minutes = total_seconds / 60;
        seconds = total_seconds - minutes * 60;
        hours = minutes / 60;
        minutes -= hours * 60;

        // Solution 2
        hours = total_seconds / 3600;
        total_seconds %= 3600;
        minutes = total_seconds / 60;
        seconds %= total_seconds;

        // cout << "Hour: " << hours << endl;
        // cout << "Minute: " << minutes << endl;
        // cout << "Second: " << seconds << endl;
    }

    /*
     * Calculate the Area of the Sphere
     */
    if (true)
    {
        const double pi = 3.14;
        double r = 10.9;
        double area = 4 * pi * pow(r, 2);
        cout << "Area: " << area << endl;
    }
}
