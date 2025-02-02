#include <iostream>
using namespace std;

void quickSort(int *arr, const int left, const int right) {
    if (left >= right) return;

    auto tempL = left, tempR = right;
    const auto pivot = arr[((left + right) / 2)];

    while (tempL < tempR) {
        while (arr[tempL] < pivot) tempL++;
        while (arr[tempR] > pivot) tempR--;

        const auto temp = arr[tempL];
        arr[tempL] = arr[tempR];
        arr[tempR] = temp;

        tempL++;
        tempR--;
    }

    quickSort(arr, left, tempR);
    quickSort(arr, tempL, right);
}

int main() {
    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];

    quickSort(A, 0, n - 1);

    int B[n];
    int size = 1;

    B[0] = A[0];
    for (int i = 0; i < n; i++) {
        if (B[size - 1] != A[i]) B[size++] = A[i];
    }

    for (int i = 0; i < size; i++) {
        cout << B[i] << " ";
    }
    cout << endl;
}
