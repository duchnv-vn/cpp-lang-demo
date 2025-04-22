#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SinhVien {
    string ma, ten, lop, email;
};

int main() {
    vector<SinhVien> ds;
    string ma, ten, lop, email;

    while (true) {
        getline(cin, ma);
        if (ma.empty()) break;

        getline(cin, ten);
        if (ten.empty()) break;

        getline(cin, lop);
        if (lop.empty()) break;

        getline(cin, email);
        if (email.empty()) break;

        ds.push_back({ma, ten, lop, email});
    }


    // Sort by ma sinh vien (mã sinh viên)
    sort(ds.begin(), ds.end(), [](SinhVien a, SinhVien b) {
        return a.ma < b.ma;
    });

    // Output
    for (auto sv: ds) {
        cout << sv.ma << " " << sv.ten << " " << sv.lop << " " << sv.email << endl;
    }

    return 0;
}
