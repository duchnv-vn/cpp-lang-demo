#include <iostream>
using namespace std;

void generateBinaryStrings(const int n, const string &binary, const char prev) {
    if (binary.length() == n) {
        cout << binary << endl;
        return;
    }

    generateBinaryStrings(n, binary + "1", '1');

    if (prev != '0') {
        generateBinaryStrings(n, binary + "0", '0');
    }
}

int main() {
    // Liet ke tat ca xau nhi phan, do dai 5, khong chua 2 so 0 lien tiep

    const int n = 5;
    generateBinaryStrings(n, "", '1');
    return 0;
}
