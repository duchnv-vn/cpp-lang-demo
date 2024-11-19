#include <iostream>
#include "student.h"
using namespace std;

float student::Get_Marks(int marknumber)
{
    return marknumber == 1 ? mark1 : mark2;
}

float student::calc_total()
{
    return (mark1 + mark2);
}

int main()
{
    student student1();
    student student2("Jack", 60, 70);
}