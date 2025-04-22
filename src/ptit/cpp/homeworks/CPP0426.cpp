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
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int A[n];
        for (int i = 0; i < n; i++) cin >> A[i];

        quickSort(A, 0, n - 1);

        int B[n];
        int count_b = 0;

        const int mid = n % 2 == 0 ? (n / 2) : ((n / 2) + 1);
        for (int i = 0; i < mid; i++) {
            const int right = n - 1 - i;
            const int left = i;

            if (left != right) {
                B[count_b++] = A[right];
                B[count_b++] = A[left];
            } else {
                B[count_b++] = A[left];
            }
        }

        for (int i = 0; i < n; i++) cout << B[i] << " ";
        cout << endl;
    }
    return 0;
}
