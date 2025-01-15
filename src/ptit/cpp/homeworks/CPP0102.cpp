#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        char C;
        cin >> C;

        if (C >= 97 && C <= 122)
            C -= 32;
        else if (C >= 65 && C <= 90)
            C += 32;

        cout << C << endl;
    }
}
