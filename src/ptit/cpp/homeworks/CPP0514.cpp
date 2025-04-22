#include <iostream>
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

string formatString(const string &str) {
    string newStr;
    for (int i = 0; i < str.length(); i++) {
        if (const char letter = str[i]; i == 0 && static_cast<int>(letter) >= 97) {
            newStr += static_cast<char>(letter - 32);
        } else if (i != 0 && static_cast<int>(letter) < 97) {
            newStr += static_cast<char>(letter + 32);
        } else {
            newStr += letter;
        }
    }

    return newStr;
}

string formatName(const string &name) {
    string newName;
    int prevSpaceIndex = -1;
    int spaceIndex = name.find(' ');
    int mustRunOneTime = 1;
    while (spaceIndex > -1 || mustRunOneTime--) {
        const string str = name.substr(prevSpaceIndex + 1, spaceIndex - prevSpaceIndex - 1);
        if (prevSpaceIndex != -1) newName += " ";
        newName += formatString(str);


        if (mustRunOneTime) {
            prevSpaceIndex = spaceIndex;
            spaceIndex = name.find(' ', spaceIndex + 1);
        }
    }

    return newName;
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
        student.fullname = formatName(student.fullname);

        // Generate student ID
        string id_order = to_string(i + 1);
        while (id_order.length() < 3) id_order = "0" + id_order;
        student.id = "B20DCCN" + id_order;

        students[i] = student;
    }

    for (int i = 0; i < N; i++) students[i].print();

    return 0;
}
