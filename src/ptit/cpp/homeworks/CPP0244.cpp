#include <iostream>
using namespace std;

void quickSort(int *arr, const int left, const int right) {
    if (left >= right) return;

    int tempL = left, tempR = right;
    const int pivot = arr[(left + right) / 2];

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

int main() {
    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];

    if (n == 1) {
        cout << A[0] << endl;
        return 0;
    }

    quickSort(A, 0, n - 1);

    int B[n];
    B[0] = A[0];
    int size = 1;

    for (int i = 1; i < n; i++) {
        if (A[i] != B[size - 1]) B[size++] = A[i];
    }

    for (int i = 0; i < size; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}
