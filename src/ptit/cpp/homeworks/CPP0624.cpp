#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

struct SinhVien {
    string ma, ten, lop, email;
};

bool thuocNganh(const SinhVien& sv, const string& nganh) {
    string key = sv.ma.substr(3, 4);
    if (nganh == "KE TOAN") return key == "DCKT";
    if (nganh == "CONG NGHE THONG TIN") return key == "DCCN" && sv.lop[0] != 'E';
    if (nganh == "AN TOAN THONG TIN") return key == "DCAT" && sv.lop[0] != 'E';
    if (nganh == "VIEN THONG") return key == "DCVT";
    if (nganh == "DIEN TU") return key == "DCDT";
    return false;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<SinhVien> ds(n);

    for (int i = 0; i < n; ++i) {
        getline(cin, ds[i].ma);
        getline(cin, ds[i].ten);
        getline(cin, ds[i].lop);
        getline(cin, ds[i].email);
    }

    int q;
    cin >> q;
    cin.ignore();
    while (q--) {
        string nganh;
        getline(cin, nganh);
        transform(nganh.begin(), nganh.end(), nganh.begin(), ::toupper);  // ⬅️ Convert to uppercase

        cout << "DANH SACH SINH VIEN NGANH " << nganh << ":" << endl;
        for (auto& sv : ds) {
            if (thuocNganh(sv, nganh)) {
                cout << sv.ma << " " << sv.ten << " " << sv.lop << " " << sv.email << endl;
            }
        }
    }

    return 0;
}
