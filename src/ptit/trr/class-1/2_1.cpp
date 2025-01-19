#include <iostream>
using namespace std;

void generate_symmetric_binary(string binary, int n, int &count) {
    if (n == 0) {
        count++;
        cout << binary << endl;
        return;
    }

    generate_symmetric_binary('0' + binary + '0', n - 1, count);
    generate_symmetric_binary('1' + binary + '1', n - 1, count);
}

int main() {
    int n;
    cout << "Nhap do dai n cua chuoi nhi phan: ";
    cin >> n;

    if (n % 2 != 0) return 1;

    int count = 0;
    generate_symmetric_binary("", n / 2, count);

    cout << endl;
    cout << "So xau nhi phan: " << count << endl;

    return 0;
}
