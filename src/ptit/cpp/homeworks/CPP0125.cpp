#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(const int n) {
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    int min, max;
    cin >> min >> max;
    if (min > max) swap(min, max);

    for (int i = min; i <= max; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}
