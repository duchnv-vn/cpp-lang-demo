#include <iostream>
using namespace std;

int minMergesToMakeSymmetric(int A[], int n) {
    int left = 0, right = n - 1;
    int count = 0;

    while (left < right) {
        if (A[left] == A[right]) {
            left++;
            right--;
        } else if (A[left] < A[right]) {
            A[left + 1] += A[left];
            left++;
            count++;
        } else {
            A[right - 1] += A[right];
            right--;
            count++;
        }
    }

    return count;
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;

        int A[n];
        for (int i = 0; i < n; i++) cin >> A[i];

        cout << minMergesToMakeSymmetric(A, n) << endl;
    }

    return 0;
}
