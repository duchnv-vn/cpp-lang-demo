#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string maSV;
    string hoTen;
    string lop;
    float diem1, diem2, diem3;
};

bool cmp(const Student &a, const Student &b) {
    return a.maSV < b.maSV;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Xóa dòng newline sau số lượng

    vector<Student> students(n);

    for (int i = 0; i < n; ++i) {
        getline(cin, students[i].maSV);
        getline(cin, students[i].hoTen);
        getline(cin, students[i].lop);
        cin >> students[i].diem1 >> students[i].diem2 >> students[i].diem3;
        cin.ignore(); // Đọc bỏ dòng trống sau 3 điểm
    }

    sort(students.begin(), students.end(), cmp);

    for (int i = 0; i < n; ++i) {
        cout << i + 1 << " "
             << students[i].maSV << " "
             << students[i].hoTen << " "
             << students[i].lop << " "
             << fixed << setprecision(1)
             << students[i].diem1 << " "
             << students[i].diem2 << " "
             << students[i].diem3 << endl;
    }

    return 0;
}
