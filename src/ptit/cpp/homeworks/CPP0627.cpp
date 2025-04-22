#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

string vietTat(string s) {
    stringstream ss(s);
    string word, res = "";
    while (ss >> word) {
        res += toupper(word[0]);
    }
    return res;
}

string toLower(const string& s) {
    string res = s;
    transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
}

struct GiangVien {
    string ma, ten, boMonVietTat;
};

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<GiangVien> ds;
    for (int i = 1; i <= n; ++i) {
        string ten, boMon;
        getline(cin, ten);
        getline(cin, boMon);
        GiangVien gv;
        gv.ma = "GV" + (i < 10 ? "0" + to_string(i) : to_string(i));
        gv.ten = ten;
        gv.boMonVietTat = vietTat(boMon);
        ds.push_back(gv);
    }

    int q;
    cin >> q;
    cin.ignore();
    while (q--) {
        string tuKhoa;
        getline(cin, tuKhoa);
        string key = toLower(tuKhoa);
        cout << "DANH SACH GIANG VIEN THEO TU KHOA " << tuKhoa << ":" << endl;
        for (const auto& gv : ds) {
            string tenLower = toLower(gv.ten);
            if (tenLower.find(key) != string::npos) {
                cout << gv.ma << " " << gv.ten << " " << gv.boMonVietTat << endl;
            }
        }
    }

    return 0;
}
