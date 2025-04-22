#include <iostream>
#include <iomanip>
using namespace std;

struct Student {
    string fullname;
    string dob;
    float subject_grade_1;
    float subject_grade_2;
    float subject_grade_3;
    float total_grade;


    Student(const string &fn, const string &birth, const float grade_1, const float grade_2,
            const float grade_3): fullname{fn}, dob{birth},
                                  subject_grade_1{grade_1}, subject_grade_2{grade_2}, subject_grade_3{grade_3},
                                  total_grade{grade_1 + grade_2 + grade_3} {
    }

    void print() {
        cout << fullname << " " << dob << " " << fixed << setprecision(1) << total_grade << endl;
    }
};

int main() {
    string fullname, dob;
    float subject_grade_1, subject_grade_2, subject_grade_3;

    getline(cin, fullname);
    cin >> dob;
    cin >> subject_grade_1;
    cin >> subject_grade_2;
    cin >> subject_grade_3;

    const auto student_1 = new Student{fullname, dob, subject_grade_1, subject_grade_2, subject_grade_3};

    student_1->print();

    delete student_1;
    return 0;
}
