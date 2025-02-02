#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;

        int A[n];
        for (int i = 0; i < n; i++) cin >> A[i];

        int count = 0;
        int left = 0;
        int right = n - 1;
        while (true) {
            if (left >= right) break;

            if (A[left] == A[right]) {
                left++;
                right--;
                continue;
            }

            if (A[left] + A[left + 1] == A[right]) {
                A[left + 1] += A[left];
                A[left] = -1;
                left++;
                count++;
                continue;
            }

            A[right - 1] += A[right];
            A[right] = -1;
            right--;
            count++;
        }

        cout << count << endl;
    }
}
