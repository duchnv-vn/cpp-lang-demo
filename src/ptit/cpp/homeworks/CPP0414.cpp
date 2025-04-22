#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int A[n];
        for (int i = 0; i < n; i++) cin >> A[i];

        int numbers[10]{0};
        for (int i = 0; i < n; i++) {
            int number = A[i];
            while (number) {
                const int part = number % 10;
                numbers[part]++;
                number /= 10;
            }
        }

        for (int i = 0; i < 10; i++) {
            if (numbers[i]) cout << i << " ";
        }

        cout << endl;
    }

    return 0;
}
