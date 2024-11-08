#include <iostream>
using namespace std;

void passParamPointer(int *param)
{
    (*param) += 10;
}

void area(double *length, double *width, double *result)
{
    (*result) = (*length) * (*width);
}

void sum_difference(int *value1, int *value2)
{
    int sum = (*value1) + (*value2);
    int difference = (*value1) > (*value2) ? (*value1) - (*value2) : (*value2) - (*value1);

    (*value1) = sum;
    (*value2) = difference;
}

int main()
{
    /*
     *
     */
    if (true)
    {
        string name = "Duc";
        string *ptrName = &name;

        int num = 10;
        passParamPointer(&num);
        cout << num << endl;
    }

    /*
     * Calculate the Area of a Rectangle Using Pointers
     */
    if (true)
    {
        double length = 4.5, width = 6.7, result = 0;
        area(&length, &width, &result);
        cout << result << endl;
    }

    /*
     * Calculate the Sum and Absolute Difference
     */
    if (true)
    {
        int value1 = 2, value2 = 6;
        sum_difference(&value1, &value2);
        cout << value1 << endl;
        cout << value2 << endl;
    }
}