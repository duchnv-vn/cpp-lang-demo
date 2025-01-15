#include <iostream>
using namespace std;

int main() {
    int unsigned N;
    cin >> N;

    int min = 10;
    int max = min * 10;
    for (int i = 2; i <= N; i++) {
        if (i % 2 != 0) continue;

        int tempNum = min;
        while (tempNum < max) {
            cout << 1 << " ";
            tempNum += 10;
        }

        cout << endl;

        min *= 10;
        max = min * 10;
    }

    return 0;
}
