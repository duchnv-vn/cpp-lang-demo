#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    /*
     * Switch statement
     */
    if (false)
    {
        int percentage = 85;

        // cout << "Grade : ";
        // switch (percentage)
        // {
        // case 90 ... 100:
        //     cout << "A";
        //     break;
        // case 70 ... 89:
        //     cout << "B";
        //     break;
        // case 50 ... 69:
        //     cout << "C";
        //     break;
        // default:
        //     cout << "D";
        // }
    }

    /*
     * Conditional operator
     */
    if (false)
    {
        int number = 25.9;
        (number < 20) ? cout << "I am less than 20 " : cout << "I am greater than 20";
    }

    /*
     * Find the Person with the Highest Salary
     */
    if (false)
    {
        int salary1 = 56000;
        int salary2 = 89000;

        cout << (salary1 > salary2 ? "person1" : "person2") << endl;
    }

    /*
     * Check if the Given Character is an Alphabet
     */
    if (true)
    {
        char character = 'a';
        if (character >= 'A' && character <= 'Z')
        {
            cout << "upper-case alphabet" << endl;
        }
        else if (character >= 'a' && character <= 'z')
        {
            cout << "lower-case alphabet" << endl;
        }
        else
        {
            cout << "not an alphabet" << endl;
        }
    }

    /*
     * Display Day of the Week
     */
    if (true)
    {
        int number = 3;
        switch (number)
        {
        case 1:
            cout << "Monday" << endl;
            break;

        case 2:
            cout << "Tuesday" << endl;
            break;

        case 3:
            cout << "Wednesday" << endl;
            break;

        case 4:
            cout << "Thursday" << endl;
            break;

        case 5:
            cout << "Friday" << endl;
            break;

        case 6:
            cout << "Saturday" << endl;
            break;

        case 7:
            cout << "Sunday" << endl;
            break;

        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
}