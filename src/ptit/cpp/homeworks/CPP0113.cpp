#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;
    if (test > 20) return 0;

    while (test--) {
        long long N;
        cin >> N;
        if (N > 1000000000) return 0;

        string finalDigitsStr;
        for (int i = 0; i < 2; i++) {
            const int finalDigit = N % 10;
            finalDigitsStr = to_string(finalDigit) + finalDigitsStr;
            N /= 10;
        }

        cout << (finalDigitsStr == "86") << endl;
    }

    return 0;
}
