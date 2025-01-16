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
        if (N < 2 || N > 1e10) return 1;

        for (long long i = 2; i * i <= N; i++) {
            while (N % i == 0) {
                cout << i << " ";
                N /= i;
            }
        }

        if (N > 1) cout << N;
        cout << endl;
    }

    return 0;
}
