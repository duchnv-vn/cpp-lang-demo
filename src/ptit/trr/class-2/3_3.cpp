/*
 * 1. Tìm tất cả hoán vị tạo thành 1 ma trận.
 * 2. Kiểm tra ma trận hợp lệ.
 * 3. Kiểm tra ma trận có tồn tại trong tập hợp kết quả bằng cách xoay và phản chiếu.
 */

#include <iostream>
#include <vector>
using namespace std;

int N = 3;
int MAGIC_SUM = 15;
int TOTAL = N * N;

vector<vector<int> > uniqueMagicSquares;

bool isMagicSquare(const vector<int> &square) {
    int grid[N][N];

    // Chuyển từ mảng 1D sang ma trận 2D
    for (int i = 0; i < TOTAL; i++) {
        grid[i / N][i % N] = square[i];
    }

    // Kiểm tra tổng hàng và cột
    for (int i = 0; i < N; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += grid[i][j];
            colSum += grid[j][i];
        }
        if (rowSum != MAGIC_SUM || colSum != MAGIC_SUM) return false;
    }

    // Kiểm tra tổng đường chéo
    int diag1 = 0;
    int diag2 = 0;
    for (int i = 0; i < N; i++) {
        diag1 += grid[i][i];
        diag2 += grid[i][N - 1 - i];
    }
    if (diag1 != MAGIC_SUM || diag2 != MAGIC_SUM) return false;

    return true;
}

vector<int> rotate90(const vector<int> &square) {
    vector<int> rotated(TOTAL);
    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            rotated[idx++] = square[j * N + i];
        }
    }
    return rotated;
}

vector<int> mirrorHorizontal(const vector<int> &square) {
    vector<int> mirrored(TOTAL);
    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            mirrored[idx++] = square[i * N + j];
        }
    }
    return mirrored;
}

vector<int> mirrorVertical(const vector<int> &square) {
    vector<int> mirrored(TOTAL);
    int idx = 0;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            mirrored[idx++] = square[i * N + j];
        }
    }
    return mirrored;
}

bool isUnique(const vector<int> &square) {
    // Sinh tất cả các phép quay và phản chiếu của square
    vector<int> rotated90 = rotate90(square);
    vector<int> rotated180 = rotate90(rotated90);
    vector<int> rotated270 = rotate90(rotated180);

    vector<int> mirroredH = mirrorHorizontal(square);
    vector<int> mirroredV = mirrorVertical(square);

    // Kiểm tra xem ma trận có duy nhất không
    for (const auto &existing: uniqueMagicSquares) {
        if (existing == square || existing == rotated90 || existing == rotated180 || existing == rotated270 ||
            existing == mirroredH || existing == mirroredV) {
            return false; // Ma trận này đã tồn tại
        }
    }
    return true;
}

void generateSquares(vector<int> &square, bool *usedNumbers, int size) {
    if (size == TOTAL) {
        if (isMagicSquare(square) && isUnique(square)) {
            uniqueMagicSquares.push_back(square);
        }
        return;
    }

    for (int i = 1; i <= TOTAL; i++) {
        if (!usedNumbers[i]) {
            usedNumbers[i] = true;
            square[size] = i;
            generateSquares(square, usedNumbers, size + 1);
            usedNumbers[i] = false;
        }
    }
}

int main() {
    cout << "Nhap bac ma tran: ";
    cin >> N;
    cout << endl;

    TOTAL = N * N;
    int sum = 0;
    for (int i = 1; i <= TOTAL; i++) sum += i;
    MAGIC_SUM = sum / N;

    vector<int> square(TOTAL);
    bool usedNumbers[TOTAL + 1] = {false};

    generateSquares(square, usedNumbers, 0);

    // In kết quả
    cout << "Tong so ket qua ma tran bac " << N << ": " << uniqueMagicSquares.size() << endl;
    for (const auto &magic: uniqueMagicSquares) {
        for (int i = 0; i < TOTAL; i++) {
            cout << magic[i] << " ";
            if ((i + 1) % N == 0) cout << endl;
        }
        cout << endl;
    }

    return 0;
}
