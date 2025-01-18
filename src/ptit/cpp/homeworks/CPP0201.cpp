#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

void quickSort(int arr[], const int left, const int right) {
    if (left >= right) return;

    const int pivot = arr[(left + right) / 2];
    int tempL = left, tempR = right;

    while (tempL <= tempR) {
        while (arr[tempL] < pivot) tempL++;
        while (arr[tempR] > pivot) tempR--;

        if (tempL < tempR) {
            const int temp = arr[tempL];
            arr[tempL] = arr[tempR];
            arr[tempR] = temp;
        }

        tempL++;
        tempR--;
    }

    quickSort(arr, left, tempR);
    quickSort(arr, tempL, right);
}

int main() {
    int test;
    cin >> test;
    if (test < 1 || test > 10) return 1;

    while (test--) {
        int N;
        cin >> N;
        if (N < 1 || N > 1e5) return 1;

        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        quickSort(A, 0, N - 1);

        int minDiff = INT_MAX;
        for (int i = 1; i < N; i++) {
            if (int diff = abs(A[i] - A[i - 1]); diff < minDiff) {
                minDiff = diff;
            }
        }

        cout << minDiff << endl;
    }

    return 0;
}
