#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string id;
    string fullname;
    string gender;
    string dob;
    string address;
    string taxCode;
    string contractSignedDate;

    void print() const {
        cout << id << " " << fullname << " " << gender << " " << dob << " " << address << " " << taxCode << " " <<
                contractSignedDate << endl;
    }
};

void extractDob(const string &d, int results[]) {
    int firstSlash = d.find('/');
    int secondSlash = d.find('/', firstSlash + 1);

    results[1] = stoi(d.substr(0, firstSlash)); // month
    results[0] = stoi(d.substr(firstSlash + 1, secondSlash - firstSlash - 1)); // day
    results[2] = stoi(d.substr(secondSlash + 1)); // year
}

bool compareDob(const string &d1, const string &d2) {
    int a[3], b[3];
    extractDob(d1, a);
    extractDob(d2, b);

    if (a[2] != b[2]) return a[2] < b[2]; // older year comes first
    if (a[1] != b[1]) return a[1] < b[1]; // older month comes next
    return a[0] < b[0]; // finally compare day
}

void quickSortByDob(Employee *arr, int left, int right) {
    if (left >= right) return;

    int l = left, r = right;
    Employee pivot = arr[(left + right) / 2];

    while (l <= r) {
        while (compareDob(arr[l].dob, pivot.dob)) l++;
        while (compareDob(pivot.dob, arr[r].dob)) r--;

        if (l <= r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }

    if (left < r) quickSortByDob(arr, left, r);
    if (l < right) quickSortByDob(arr, l, right);
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    Employee employees[N];

    for (int i = 0; i < N; i++) {
        Employee e;
        getline(cin, e.fullname);
        getline(cin, e.gender);
        getline(cin, e.dob);
        getline(cin, e.address);
        getline(cin, e.taxCode);
        getline(cin, e.contractSignedDate);

        string id = to_string(i + 1);
        while (id.length() < 5) id = "0" + id;
        e.id = id;

        employees[i] = e;
    }

    quickSortByDob(employees, 0, N - 1);

    for (int i = 0; i < N; i++) {
        employees[i].print();
    }

    return 0;
}
