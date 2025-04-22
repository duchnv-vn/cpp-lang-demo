#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

struct Student {
    string id;
    string fullname;
    string className;
    string dob;
    float gpa{};

    void print() const {
        cout << id << " " << fullname << " " << className << " " << dob << " " << fixed << setprecision(2) << gpa <<
                endl;
    }
};

string formatDOB(const string &date) {
    const int firstSlash = date.find('/');
    const int secondSlash = date.find('/', firstSlash + 1);

    string day = date.substr(0, firstSlash);
    string month = date.substr(firstSlash + 1, secondSlash - firstSlash - 1);
    const string year = date.substr(secondSlash + 1);

    if (day.length() == 1) day = "0" + day;
    if (month.length() == 1) month = "0" + month;

    return day + "/" + month + "/" + year;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    Student students[N];

    for (int i = 0; i < N; i++) {
        Student student;

        getline(cin, student.fullname);
        getline(cin, student.className);
        getline(cin, student.dob);
        cin >> student.gpa;
        cin.ignore();

        student.dob = formatDOB(student.dob);

        // Generate student ID
        string id_order = to_string(i + 1);
        while (id_order.length() < 3) id_order = "0" + id_order;
        student.id = "B20DCCN" + id_order;

        students[i] = student;
    }

    for (int i = 0; i < N; i++) students[i].print();

    return 0;
}
