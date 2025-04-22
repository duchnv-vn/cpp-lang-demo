/*
 * Thuật toán sinh hoán vị kế tiếp của 1, 2, ..., n:
 * 
 * Thuật toán quay lui (Backtracking):
 *    - Sử dụng mảng đánh dấu các số đã được sử dụng
 *    - Tại mỗi vị trí, thử tất cả các số từ 1 đến n chưa được sử dụng
 *    - Đánh dấu số đã sử dụng, đệ quy sinh hoán vị cho vị trí tiếp theo
 *    - Sau khi đệ quy, bỏ đánh dấu số đã sử dụng (backtrack) để thử các khả năng khác
 *    - Khi đã điền đủ n vị trí, in ra hoán vị
 */

#include <iostream>
using namespace std;

void printArr(const int *arr, const int n) {
    cout << "{ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << " }" << endl;
}

void generateNextPermutation(int *arr, bool *usedNumbers, const int n, const int pos) {
    if (pos == n) return printArr(arr, n);

    for (int i = 0; i < n; i++) {
        if (usedNumbers[i]) continue;
        usedNumbers[i] = true;
        arr[pos] = i + 1;
        generateNextPermutation(arr, usedNumbers, n, pos + 1);
        usedNumbers[i] = false;
    }
}

int main() {
    int n;
    cin >> n;

    if (n < 1) return 0;

    bool usedNumbers[n]{0};
    for (int i = 0; i < n; i++) usedNumbers[i] = false;
    int numbers[n]{0};
    generateNextPermutation(numbers, usedNumbers, n, 0);

    return 0;
}
