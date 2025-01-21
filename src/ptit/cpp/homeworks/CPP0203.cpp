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
    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;

        int A[n];
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            A[i] = v;
        }

        quickSort(A, 0, n - 1);

        if (A[n - 1] <= 0) {
            cout << 1 << endl;
            return 0;
        }

        if (n == 1) {
            if (A[0] > 1) {
                cout << 1 << endl;
                return 0;
            }

            cout << 2 << endl;
            return 0;
        }

        for (int i = 0; i < n; i++) {
            if (i + 1 == n) {
                cout << (A[i] + 1) << endl;
                break;
            }

            if (A[i] < 0 && A[i + 1] <= 0) continue;

            if (A[i + 1] - A[i] > 1) {
                if (A[i] < 0 && A[i + 1] - 0 > 1) {
                    cout << 1 << endl;
                    break;
                }

                if (A[i] > 0) {
                    cout << (A[i] + 1) << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
