#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        long long N;
        cin >> N;

        const long sum = N * (N + 1) / 2;
        cout << sum << endl;
    }

    return 0;
}
