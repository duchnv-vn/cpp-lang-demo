#include <iostream>
using namespace std;

struct Employee {
    string code;
    string fullname;
    string sex;
    string dob;
    string address;
    string tax_code;
    string contract_signed_date;

    Employee(const string &fn, const string &s, const string &birth, const string &add, const string &tax,
             const string &csd): code{"00001"}, fullname{fn}, sex{s},
                                 dob{birth}, address{add}, tax_code{tax}, contract_signed_date{csd} {
    }


    void print() {
        cout << code << " " << fullname << " " << sex << " " << dob << " " << address << " " << tax_code << " " <<
                contract_signed_date << endl;
    }
};

int main() {
    string fullname, gender, dob, address, tax_code, contract_signed_date;

    getline(cin, fullname);
    getline(cin, gender);
    getline(cin, dob);
    getline(cin, address);
    getline(cin, tax_code);
    getline(cin, contract_signed_date);

    const auto employee_1 = new Employee{fullname, gender, dob, address, tax_code, contract_signed_date};

    employee_1->print();

    delete employee_1;
    return 0;
}
