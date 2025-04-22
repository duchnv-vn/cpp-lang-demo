#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int id_counter = 1; // Biến toàn cục để tăng mã nhân viên

class NhanVien {
private:
    string id;
    string name;
    string gender;
    string dob;
    string address;
    string tax;
    string contract_date;

public:
    friend istream &operator>>(istream &in, NhanVien &nv);

    friend ostream &operator<<(ostream &out, const NhanVien &nv);
};

istream &operator>>(istream &in, NhanVien &nv) {
    getline(in, nv.name);
    getline(in, nv.gender);
    getline(in, nv.dob);
    getline(in, nv.address);
    getline(in, nv.tax);
    getline(in, nv.contract_date);

    // Tạo mã nhân viên tự động
    stringstream ss;
    ss << setw(5) << setfill('0') << id_counter++;
    nv.id = ss.str();

    return in;
}

ostream &operator<<(ostream &out, const NhanVien &nv) {
    out << nv.id << " " << nv.name << " " << nv.gender << " " << nv.dob << " "
            << nv.address << " " << nv.tax << " " << nv.contract_date;
    return out;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // bỏ dòng '\n' sau khi đọc số lượng

    NhanVien ds[50];

    for (int i = 0; i < n; ++i) {
        cin >> ds[i];
    }

    for (int i = 0; i < n; ++i) {
        cout << ds[i] << endl;
    }

    return 0;
}
