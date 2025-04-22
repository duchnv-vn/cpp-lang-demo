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
    const int size = 4;
    int binary[size]{0};

    // He so phuong trinh muc tieu
    const int objectiveCoefficients[] = {7, 3, 2, 1};

    // He so ham gioi han
    const int constraintCoefficients[] = {5, 3, 6, 4};

    // Gioi han tren
    const int limit = 12;

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
