#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        int n, m;
        cin >> n >> m;

        const int total = n * m;
        int A[total];
        for (int i = 0; i < total; i++) cin >> A[i];

        const int matrix_outline_number = 2 * m + 2 * (n - 2);
        const int pivot_number = total - matrix_outline_number;

        int B[total];
        const int middle_index = total / 2;
        const int pivot_start_index = middle_index - (pivot_number - 1);
        for (int i = 0; i <= middle_index; i++) {
            if (i == middle_index && pivot_number == 0) {
                continue;
            }

            if (pivot_number != 0 && i >= pivot_start_index) {
                B[i] = A[i];
                continue;
            }

            if (pivot_number != 0 && i == (pivot_start_index - 2)) {
                if (const int idx = pivot_start_index + pivot_number; idx < total) {
                    B[idx] = A[i];
                    B[idx - pivot_number - 1] = A[total - 1 - i];
                    continue;
                }
            }

            if ((i + 1) == matrix_outline_number / 2) {
                if (pivot_number != 0) {
                    B[0] = A[i];
                    B[total - 1] = A[i + pivot_number + 1];
                } else {
                    B[0] = A[i + 1];
                    B[total - 1] = A[i];
                }
                continue;
            }

            B[i + 1] = A[i];
            B[total - 1 - i - 1] = A[total - 1 - i];
        }

        for (int j = 0; j < total; j++) {
            cout << B[j] << " ";
        }
        cout << endl;
    }
}
