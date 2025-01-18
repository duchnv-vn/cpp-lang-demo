#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int test;
    cin >> test;
    if (test < 1 || test > 100) return 1;

    while (test--) {
        long long N;
        cin >> N;
        if (N < 1 || N > static_cast<long long>(1e6)) return 1;

        for (long long i = 2; i <= static_cast<long long>(sqrt(N)); i++) {
            bool isPrime = true;

            for (int j = 2; j <= sqrt(i); j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }

            const long long desiredNumber = i * i;

            if (isPrime) {
                cout << desiredNumber << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
