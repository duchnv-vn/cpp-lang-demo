/*
* Chi tiết thuật toán:
 * 1. Giảm hàng và cột để có ma trận chi phí tối thiểu.
 * 2. Tính cận dưới của tổng chi phí bằng cách cộng tất cả hằng số rút gọn hàng và cột.
 * 3. Chọn cạnh sao cho cận dưới của tổng chi phí của hành trình chứa cạnh là lớn nhất.
 * 4. Ghi nhận lại vị trí các cạnh.
 * 5. Xây dựng đường đi hoàn chỉnh từ tập các cạnh.
 */

#include <array>
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
using namespace std;

// Cau truc de luu tru mot canh trong duong di
struct Edge {
    int from;
    int to;
    int cost;

    Edge(int f, int t, int c) : from(f), to(t), cost(c) {
    }
};

int main() {
    const auto n = 6; // So luong thanh pho
    vector<vector<int> > originalMatrix = {
        {8, 31, 15, 23, 10, 17},
        {16, -1, 24, 7, 12, 12},
        {34, 3, -1, 25, 54, 25},
        {15, 20, 33, -1, 50, 40},
        {16, 10, 32, 3, -1, 23},
        {18, 20, 13, 28, 21, -1}
    };

    // Luu tru duong di toi uu
    vector<Edge> optimalPath;

    // Luu tru cac thanh pho da tham
    vector<bool> visited(n, false);

    // Luu tru cac canh da chon
    vector<array<int, 2> > selectedEdges;

    // Tong chi phi
    int totalCost = 0;

    // Ma tran chi phi hien tai
    vector<vector<int> > matrix = originalMatrix;

    // So luong hang va cot hien tai
    int currentRow = n;
    int currentCol = n;

    cout << "Ma tran chi phi ban dau:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (originalMatrix[i][j] == -1) {
                cout << setw(4) << "X";
            } else {
                cout << setw(4) << originalMatrix[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;

    // Luu tru anh xa giua chi so trong ma tran hien tai va chi so thanh pho ban dau
    vector<int> rowMapping(n);
    vector<int> colMapping(n);
    for (int i = 0; i < n; i++) {
        rowMapping[i] = i;
        colMapping[i] = i;
    }

    while (selectedEdges.size() < n) {
        cout << "Kich thuoc ma tran hien tai: " << currentRow << "x" << currentCol << endl;

        // Tim gia tri nho nhat trong moi hang
        int lowestBoundary = 0;
        vector<int> rowMins(currentRow, numeric_limits<int>::max());
        for (int i = 0; i < currentRow; i++) {
            for (int j = 0; j < currentCol; j++) {
                if (matrix[i][j] != -1 && matrix[i][j] < rowMins[i]) {
                    rowMins[i] = matrix[i][j];
                }
            }
            if (rowMins[i] == numeric_limits<int>::max()) {
                rowMins[i] = 0; // Neu khong co gia tri hop le
            }
        }
        // Giam hang
        for (int i = 0; i < currentRow; i++) {
            if (rowMins[i] > 0) {
                for (int j = 0; j < currentCol; j++) {
                    if (matrix[i][j] != -1) {
                        matrix[i][j] -= rowMins[i];
                    }
                }
                lowestBoundary += rowMins[i];
            }
        }

        cout << "Ma tran sau khi giam hang:" << endl;
        for (int i = 0; i < currentRow; i++) {
            for (int j = 0; j < currentCol; j++) {
                if (matrix[i][j] == -1) {
                    cout << setw(4) << "X";
                } else {
                    cout << setw(4) << matrix[i][j];
                }
            }
            cout << endl;
        }
        cout << "Can duoi sau khi giam hang: " << lowestBoundary << endl << endl;

        // Tim gia tri nho nhat trong moi cot
        vector<int> colMins(currentCol, numeric_limits<int>::max());
        for (int j = 0; j < currentCol; j++) {
            for (int i = 0; i < currentRow; i++) {
                if (matrix[i][j] != -1 && matrix[i][j] < colMins[j]) {
                    colMins[j] = matrix[i][j];
                }
            }
            if (colMins[j] == numeric_limits<int>::max()) {
                colMins[j] = 0; // Neu khong co gia tri hop le
            }
        }
        // Giam cot
        for (int j = 0; j < currentCol; j++) {
            if (colMins[j] > 0) {
                for (int i = 0; i < currentRow; i++) {
                    if (matrix[i][j] != -1) {
                        matrix[i][j] -= colMins[j];
                    }
                }
                lowestBoundary += colMins[j];
            }
        }

        cout << "Ma tran sau khi giam cot:" << endl;
        for (int i = 0; i < currentRow; i++) {
            for (int j = 0; j < currentCol; j++) {
                if (matrix[i][j] == -1) {
                    cout << setw(4) << "X";
                } else {
                    cout << setw(4) << matrix[i][j];
                }
            }
            cout << endl;
        }
        cout << "Can duoi sau khi giam cot: " << lowestBoundary << endl << endl;

        // Chon canh dua tren hoi tiec toi da
        int maxReduce = -1;
        array<int, 2> targetBranchPoint = {0, 0};

        for (int i = 0; i < currentRow; i++) {
            for (int j = 0; j < currentCol; j++) {
                if (matrix[i][j] == 0) {
                    int rowMin = numeric_limits<int>::max();
                    int colMin = numeric_limits<int>::max();

                    // Tim gia tri nho nhat trong hang (lon hon 0)
                    for (int k = 0; k < currentCol; k++) {
                        if (k != j && matrix[i][k] != -1 && (
                                matrix[i][k] < rowMin || rowMin == numeric_limits<int>::max())) {
                            rowMin = matrix[i][k];
                        }
                    }
                    if (rowMin == numeric_limits<int>::max()) rowMin = 0;

                    // Tim gia tri nho nhat trong cot (lon hon 0)
                    for (int k = 0; k < currentRow; k++) {
                        if (k != i && matrix[k][j] != -1 && (
                                matrix[k][j] < colMin || colMin == numeric_limits<int>::max())) {
                            colMin = matrix[k][j];
                        }
                    }
                    if (colMin == numeric_limits<int>::max()) colMin = 0;

                    const int reduce = rowMin + colMin;
                    if (reduce > maxReduce) {
                        maxReduce = reduce;
                        targetBranchPoint = {i, j};
                    }
                }
            }
        }

        int originalRow = rowMapping[targetBranchPoint[0]];
        int originalCol = colMapping[targetBranchPoint[1]];
        // Them canh vao duong di
        selectedEdges.push_back({originalRow, originalCol});
        // Cap nhat chi phi
        totalCost += originalMatrix[originalRow][originalCol];

        cout << "Chon canh: (" << originalRow << ", " << originalCol << ") voi giam thieu toi da: " << maxReduce <<
                endl;

        // Danh dau canh cam di
        for (int i = 0; i < currentRow; i++) {
            for (int j = 0; j < currentCol; j++) {
                if (rowMapping[i] == originalCol && colMapping[j] == originalRow) {
                    matrix[i][j] = -1;
                }
            }
        }

        // Tao ma tran moi bang cach loai bo canh chon
        vector<vector<int> > newMatrix;
        vector<int> newRowMapping;
        vector<int> newColMapping;

        for (int i = 0; i < currentRow; i++) {
            if (i == targetBranchPoint[0]) continue;

            vector<int> newRow;
            for (int j = 0; j < currentCol; j++) {
                if (j != targetBranchPoint[1]) {
                    newRow.push_back(matrix[i][j]);
                }
            }

            if (!newRow.empty()) {
                newMatrix.push_back(newRow);
                newRowMapping.push_back(rowMapping[i]);
            }
        }

        for (int j = 0; j < currentCol; j++) {
            if (j != targetBranchPoint[1]) {
                newColMapping.push_back(colMapping[j]);
            }
        }

        // Cap nhat ma tran va anh xa
        matrix = newMatrix;
        rowMapping = newRowMapping;
        colMapping = newColMapping;

        currentRow = matrix.size();
        currentCol = (currentRow > 0) ? matrix[0].size() : 0;

        cout << "Ma tran sau khi loai bo hang va cot:" << endl;
        for (int i = 0; i < currentRow; i++) {
            for (int j = 0; j < currentCol; j++) {
                if (matrix[i][j] == -1) {
                    cout << setw(4) << "X";
                } else {
                    cout << setw(4) << matrix[i][j];
                }
            }
            cout << endl;
        }
        cout << "--------------------------------------" << endl;

        // Neu chi con 2 thanh pho, them canh cuoi cung va ket thuc bang cach tim 2 thanh pho cuoi cung chua duoc ket noi
        if (selectedEdges.size() == n - 1) {
            int lastCity1 = -1, lastCity2 = -1;

            for (int i = 0; i < n; i++) {
                bool isFrom = false, isTo = false;

                for (const auto &edge: selectedEdges) {
                    if (edge[0] == i) isFrom = true;
                    if (edge[1] == i) isTo = true;
                }

                if (!isFrom) lastCity1 = i;
                if (!isTo) lastCity2 = i;
            }

            if (lastCity1 != -1 && lastCity2 != -1) {
                selectedEdges.push_back({lastCity1, lastCity2});
                totalCost += originalMatrix[lastCity1][lastCity2];

                cout << "Them canh cuoi cung: (" << lastCity1 << ", " << lastCity2 << ")" << endl;
            }
            break;
        }
    }

    // Sap xep cac canh de tao thanh duong di
    vector<Edge> path;
    for (const auto &edge: selectedEdges) {
        path.push_back(Edge(edge[0], edge[1], originalMatrix[edge[0]][edge[1]]));
    }

    // Hien thi ket qua
    cout << "Ket qua toi uu:" << endl;

    // Xay dung duong di tu cac canh da chon
    vector<int> tour;
    vector<bool> visitedInTour(n, false);
    int currentCity = 0; // Bat dau tu thanh pho 0
    tour.push_back(currentCity);
    visitedInTour[currentCity] = true;

    // Xay dung duong di hoan chinh
    while (tour.size() < n) {
        bool foundNext = false;
        for (const auto &edge: selectedEdges) {
            if (edge[0] == currentCity && !visitedInTour[edge[1]]) {
                currentCity = edge[1];
                tour.push_back(currentCity);
                visitedInTour[currentCity] = true;
                foundNext = true;
                break;
            }
        }

        // Neu khong tim thay canh tiep theo, co the duong di bi gian doan
        if (!foundNext) {
            // Tim thanh pho chua tham gan nhat
            for (int i = 0; i < n; i++) {
                if (!visitedInTour[i]) {
                    // Tim canh ket noi tu mot thanh pho da tham den thanh pho chua tham
                    for (const auto &edge: selectedEdges) {
                        if (visitedInTour[edge[0]] && edge[1] == i) {
                            currentCity = i;
                            tour.push_back(currentCity);
                            visitedInTour[currentCity] = true;
                            foundNext = true;
                            break;
                        }
                    }
                    if (foundNext) break;
                }
            }
        }

        // Neu van khong tim thay, co the duong di khong lien tuc
        if (!foundNext) {
            // Tim thanh pho chua tham bat ky
            for (int i = 0; i < n; i++) {
                if (!visitedInTour[i]) {
                    currentCity = i;
                    tour.push_back(currentCity);
                    visitedInTour[currentCity] = true;
                    break;
                }
            }
        }
    }

    // Them canh quay ve thanh pho xuat phat
    tour.push_back(0);

    // Tinh toan chi phi thuc te cua duong di
    int actualCost = 0;
    for (int i = 0; i < tour.size() - 1; i++) {
        int from = tour[i];
        int to = tour[i + 1];
        actualCost += originalMatrix[from][to];
    }

    cout << "Duong di: ";
    for (int i = 0; i < tour.size(); i++) {
        cout << tour[i];
        if (i < tour.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;

    cout << "Tong chi phi: " << actualCost << endl;

    return 0;
}
