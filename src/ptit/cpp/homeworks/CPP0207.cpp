#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        int n, d;
        cin >> n >> d;

        int A[n];
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            A[i] = v;
        }
        int B[n];
        for (int i = 0; i < n; i++) {
            int idx = i + d;
            if (idx >= n) idx -= n;
            B[i] = A[idx];
        }

        for (int i = 0; i < n; i++)
            cout << B[i] << " ";
        cout << endl;
    }
}
