#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct SinhVien {
    string ma, ten, lop, email;
};

bool cmp(const SinhVien& a, const SinhVien& b) {
    if (a.lop != b.lop) return a.lop < b.lop;
    return a.ma < b.ma;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Bỏ dòng trống sau cin >> n

    vector<SinhVien> ds(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, ds[i].ma);
        getline(cin, ds[i].ten);
        getline(cin, ds[i].lop);
        getline(cin, ds[i].email);
    }

    sort(ds.begin(), ds.end(), cmp);

    for (auto& sv : ds) {
        cout << sv.ma << " " << sv.ten << " " << sv.lop << " " << sv.email << endl;
    }

    return 0;
}
