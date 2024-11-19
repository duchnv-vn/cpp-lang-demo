#ifndef STUDENT_H
#define STUDENT_H
using namespace std;

class student
{
    string name;
    float mark1;
    float mark2;

public:
    student()
    {
        mark1 = 0;
        mark2 = 0;
    };

    student(string n, float m1, float m2)
    {
        name = n;
        mark1 = m1;
        mark2 = m2;
    };

    float Get_Marks(int marknumber);

    float calc_total();
};

#endif // STUDENT_H
