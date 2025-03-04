#include <iostream>
using namespace std;

void quickSort(int *arr, int left, int right) {
    if (left >= right) return;

    int tempL = left, tempR = right;
    int pivot = arr[(left + right) / 2];

    while (tempL <= tempR) {
        while (arr[tempL] < pivot) tempL++;
        while (arr[tempR] > pivot) tempR--;

        if (tempL <= tempR) {
            swap(arr[tempL], arr[tempR]);
            tempL++;
            tempR--;
        }
    }

    if (left < tempR) quickSort(arr, left, tempR);
    if (tempL < right) quickSort(arr, tempL, right);
}

int findSmallestMissingPositive(int A[], int n) {
    quickSort(A, 0, n - 1);

    int smallestMissing = 1;
    for (int i = 0; i < n; i++) {
        if (A[i] < 1) continue;
        if (A[i] == smallestMissing) {
            smallestMissing++;
        } else if (A[i] > smallestMissing) {
            break;
        }
    }

    return smallestMissing;
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;

        int A[n];
        for (int i = 0; i < n; i++) cin >> A[i];

        cout << findSmallestMissingPositive(A, n) << endl;
    }

    return 0;
}
