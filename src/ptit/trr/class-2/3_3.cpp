/*
 * 1. Tìm tổng cộng chuẩn của ma trận bậc n theo công thức: n * (n * n + 1) / 2

 * 2. Tìm tất cả hoán vị tạo thành 1 ma trận hoàn chỉnh bằng phương pháp backtracking và đệ quy.

 * 3. Trong quá trình thêm phần tử vào ma trận, khi đủ 1 hàng/cột,
 *    sẽ kiểm tra tổng cộng phần tử hàng/cột có bằng tổng chuẩn của ma trận để loại sớm trường hợp không hợp lệ.

 * 4. Sau khi ma trận được điền đủ phần tử,
 *    kiểm tra ma trận có hợp lệ bằng cách tính tổng cộng phần tử hàng/cột, đường chéo chính và đường chéo phụ có bằng tổng chuẩn của ma trận.

 * 5. Xoay và phản chiếu ma trận hợp lệ và kiểm tra các biến hình có trùng lặp trong tập hợp kết quả bằng cách so sánh chuỗi dãy số.

 * 6. Thêm ma trận vào tập hợp kết quả và in kết quả ra màn hình console.
 */

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>
using namespace std;

bool isMagicSquare(const vector<vector<int> > &square, const int n, const int sum) {
    // Kiểm tra tổng cộng của hàng
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            if (square[i][j] == 0) return false;
            rowSum += square[i][j];
        }
        if (rowSum != sum) return false;
    }

    // Kiểm tra tổng cộng của cột
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += square[i][j];
        }
        if (colSum != sum) return false;
    }

    // Kiểm tra tổng cộng của đường chéo chính
    int diagSum = 0;
    for (int i = 0; i < n; i++) {
        diagSum += square[i][i];
    }
    if (diagSum != sum) return false;

    // Kiểm tra tổng cộng của đường chéo phụ
    diagSum = 0;
    for (int i = 0; i < n; i++) {
        diagSum += square[i][n - 1 - i];
    }
    return diagSum == sum;
}

vector<vector<int> > rotate90(const vector<vector<int> > &square, const int n) {
    vector<vector<int> > rotated(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - 1 - i] = square[i][j];
        }
    }
    return rotated;
}

vector<vector<int> > horizontalReflect(const vector<vector<int> > &square, const int n) {
    vector<vector<int> > reflected(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            reflected[i][n - 1 - j] = square[i][j];
        }
    }
    return reflected;
}

string squareToString(const vector<vector<int> > &square) {
    string result;
    for (const auto &row: square) {
        for (const int val: row) {
            result += to_string(val) + ",";
        }
    }
    return result;
}

set<string> getTransformations(const vector<vector<int> > &square, const int n) {
    set<string> transformations;
    auto current = square;

    // Xoay ma trận
    for (int i = 0; i < 4; i++) {
        transformations.insert(squareToString(current));
        current = rotate90(current, n);
    }

    // Phản chiếu ngang và xoay ma trận
    current = horizontalReflect(square, n);
    for (int i = 0; i < 4; i++) {
        transformations.insert(squareToString(current));
        current = rotate90(current, n);
    }

    return transformations;
}

// Kiểm tra tổng cộng của hàng hiện tại có lớn hơn tổng chuẩn của ma trận không
bool isPartialRowValid(const vector<vector<int> > &square, const int row, const int col, const int n,
                       const int targetSum) {
    if (col == n - 1) {
        int sum = 0;
        for (int j = 0; j <= col; j++) {
            sum += square[row][j];
        }
        return sum == targetSum;
    }
    return true;
}

// Kiểm tra tổng cộng của cột hiện tại có lớn hơn tổng chuẩn của ma trận không
bool isPartialColumnValid(const vector<vector<int> > &square, const int row, const int col, const int n,
                          const int targetSum) {
    if (row == n - 1) {
        int sum = 0;
        for (int i = 0; i <= row; i++) {
            sum += square[i][col];
        }
        return sum == targetSum;
    }
    return true;
}

// Tìm ma trận hợp lệ bằng phương pháp Backtracking
void findMagicSquare(vector<vector<int> > &square, const int pos, unordered_set<int> &used,
                     set<string> &uniqueSquares, const int n, const int targetSum) {
    if (pos == n * n) {
        if (isMagicSquare(square, n, targetSum)) {
            const auto transformations = getTransformations(square, n);

            bool isUnique = true;
            for (const string &trans: transformations) {
                if (uniqueSquares.find(trans) != uniqueSquares.end()) {
                    isUnique = false;
                    break;
                }
            }

            if (isUnique) {
                uniqueSquares.insert(squareToString(square));

                cout << "Tong ket qua hien tai: " << uniqueSquares.size() << endl;
                cout << "Ma tran hop le:" << endl;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cout << square[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
        return;
    }

    const int currRow = pos / n;
    const int currCol = pos % n;
    for (int num = 1; num <= n * n; num++) {
        if (used.find(num) == used.end()) {
            square[currRow][currCol] = num;

            // Loại bỏ sớm trường hợp không hợp lệ
            if (!isPartialRowValid(square, currRow, currCol, n, targetSum)) continue;
            if (!isPartialColumnValid(square, currRow, currCol, n, targetSum)) continue;

            used.insert(num);
            findMagicSquare(square, pos + 1, used, uniqueSquares, n, targetSum);
            used.erase(num);
        }
    }
}

void findMagicSquares(const int n) {
    vector<vector<int> > square(n, vector<int>(n, 0));
    unordered_set<int> used;
    set<string> results;

    const int sum = n * (n * n + 1) / 2;
    findMagicSquare(square, 0, used, results, n, sum);

    cout << "Tong ket qua tim dc cuoi cung: " << results.size() << endl;
}

int main() {
    cout << "Tim ket qua ma tran bac 3:" << endl;
    findMagicSquares(3); // Tổng kết quả: 1 

    cout << "Tim ket qua ma tran bac 4:" << endl;
    findMagicSquares(4); // Tổng kết quả: quá lớn, chưa đếm được

    return 0;
}
