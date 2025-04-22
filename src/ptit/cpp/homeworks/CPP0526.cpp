#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Person {
    string name;
    int day, month, year;
};

Person parseInput(const string& line) {
    stringstream ss(line);
    Person p;
    string date;
    ss >> p.name >> date;

    p.day = stoi(date.substr(0, 2));
    p.month = stoi(date.substr(3, 2));
    p.year = stoi(date.substr(6, 4));

    return p;
}

bool isYounger(const Person &a, const Person &b) {
    if (a.year != b.year) return a.year > b.year;
    if (a.month != b.month) return a.month > b.month;
    return a.day > b.day;
}

bool isOlder(const Person &a, const Person &b) {
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // bỏ dòng '\n' sau khi đọc n

    vector<Person> people(n);

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        people[i] = parseInput(line);
    }

    Person youngest = people[0];
    Person oldest = people[0];

    for (int i = 1; i < n; ++i) {
        if (isYounger(people[i], youngest)) {
            youngest = people[i];
        }
        if (isOlder(people[i], oldest)) {
            oldest = people[i];
        }
    }

    cout << youngest.name << endl;
    cout << oldest.name << endl;

    return 0;
}
