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
        int N;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        quickSort(arr, 0, N - 1);

        int count = 0;
        bool isDuplicating = false;
        for (int i = 1; i < N; i++) {
            if (arr[i] == arr[i - 1]) {
                if (isDuplicating)
                    count++;
                else
                    count += 2;

                isDuplicating = true;
            } else {
                isDuplicating = false;
            }
        }

        cout << count << endl;
    }

    return 0;
}
