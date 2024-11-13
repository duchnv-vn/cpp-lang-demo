#include <iostream>
using namespace std;

struct MyStudent
{
    int id;
    string name;
    float gpa;
};

void printCopyStudentData(MyStudent student)
{
    cout << "Id: " << student.id << endl;
    cout << "Name: " << student.name << endl;
    cout << "GPA: " << student.gpa << endl;
}

void printReferenceStudentData(MyStudent *ptrStudent)
{
    cout << "Id: " << ptrStudent->id << endl;
    cout << "Name: " << ptrStudent->name << endl;
    cout << "GPA: " << ptrStudent->gpa << endl;
}

// Structure to store complex number
struct complex_number
{
    double real;
    double imaginary;
};

// Function to subtract two complex numbers
complex_number subtract(struct complex_number c1, struct complex_number c2)
{
    return {
        .real = c1.real - c2.real,
        .imaginary = c1.imaginary - c2.imaginary,
    };
}

// Structure to store Student information
struct Student
{
    string name;
    double marks[4];
};

// Function to calculate percentage
double calculate_percentage(struct Student s)
{
    double total_mark = 0;

    for (int i = 0; i < 4; i++)
        total_mark += s.marks[i];

    return (total_mark / (4 * 100)) * 100;
}

// Structure to store Account information
struct Account
{
    string name;
    int number;
    double balance;
};

// Function to find account numbers with less than 500 balance
void check_account(struct Account p[], int arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = p[i].balance < 500 ? p[i].number : -1;
}

int main()
{
    if (false)
    {
        MyStudent student1 = {
            .id = 1,
            .name = "Duc Huynh",
            .gpa = 3.5f,
        };
        printCopyStudentData(student1);

        MyStudent student2 = {2, "Duc Huynh 2", 4.0};
        MyStudent *ptrStudent2 = &student2;
        printReferenceStudentData(ptrStudent2);

        MyStudent students[5];
        students[0] = student1;
        students[1] = student2;
    }

    /*
     * Subtract Two Complex Numbers
     */
    if (false)
    {
        complex_number num = subtract({12.3, 67.4}, {54.2, 90.8});
        cout << "Real part: " << num.real << endl;
        cout << "Imaginary part: " << num.imaginary << endl;
    }

    /*
     * Calculate Overall Percentage of Student's Marks
     */
    if (false)
    {
        double average_mark = calculate_percentage({"John", {30.500000, 49.700000, 22.300000, 32.900000}});
        cout << "Average mark: " << average_mark << endl;
    }

    /*
     * Account Number of Customers with Balance < $500
     */
    if (true)
    {
        int account_numbers[] = {0, 0, 0};
        Account accounts[] = {{"John", 578328, 890.000000}, {"Alex", 908210, 430.200000}, {"Kim", 165216, 98.500000}};
        check_account(accounts, account_numbers, 3);
        for (int i = 0; i < 3; i++)
            cout << "Index " << i << ": " << account_numbers[i] << endl;
    }
}