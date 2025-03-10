/*
 * Chi tiết thuật toán:
 *  1. Dùng thuật toán sinh dãy nhị phân để sinh và duyệt toàn bộ phương án của tập 10 món đồ.
 *  2. Tại mỗi phương án, tính tổng giá trị bằng phương trình thứ 1 (hàm f(x)) và tính tổng khối lượng bằng phương trình thứ 2 (hàm g(x)).
 *  3. So sánh tổng khối lượng nếu nhỏ hơn hoặc bằng 10 và tổng giá trị lớn hơn so với giá trị lớn nhất trước đó thì gán giá trị lớn nhất bằng tổng giá trị của phương án hiện tại.
 */

#include <iostream>
using namespace std;

int generateBinary(int *binary, const int size) {
    int count = size;
    for (int i = size - 1; i >= 0; i--) {
        if (binary[i] == 1) {
            count -= 1;
            binary[i] = 0;
            continue;
        }

        if (binary[i] == 0) {
            binary[i] = 1;
            return count;
        }
    }

    return count;
}

int main() {
    const int size = 10;
    int binary[size]{0};

    // He so phuong trinh muc tieu
    const int objectiveCoefficients[] = {30, 19, 13, 38, 20, 6, 8, 19, 10, 11};

    // He so ham gioi han
    const int constraintCoefficients[] = {15, 12, 9, 27, 15, 5, 8, 20, 12, 15};

    // Gioi han tren
    const int limit = 62;

    int constraintValue = 0;
    int sum = 0;
    int maxValue = 0;
    int maxDecisionPtr[size]{0};

    bool shouldRun = false;
    do {
        sum = 0;
        constraintValue = 0;

        for (int i = 0; i < size; i++) {
            sum += objectiveCoefficients[i] * binary[i];
            constraintValue += constraintCoefficients[i] * binary[i];
        }

        // So sanh gioi han va tim gia tri lon nhat tiep theo
        if (constraintValue <= limit && sum > maxValue) {
            maxValue = sum;

            for (int i = 0; i < size; i++)
                maxDecisionPtr[i] = binary[i];
        }

        // Sinh chuoi nhi phan ke tiep
        const auto idx = generateBinary(binary, size);

        // Chuonh trinh dung khi chuoi nhi phan duoc lap day boi 1
        shouldRun = idx != 0;
    } while (shouldRun);

    cout << "Gia tri lon nhat: " << maxValue << endl;
    for (int i = 0; i < size; i++)
        cout << "X" << (i + 1) << ": " << maxDecisionPtr[i] << endl;

    return 0;
}
