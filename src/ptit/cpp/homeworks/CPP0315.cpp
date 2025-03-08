#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        int N;
        cin >> N;

        if (N < 20) return -1;

        vector<int> numbers;
        int remain = N;
        int previousNumber = numeric_limits<int>::max();
        bool isInOrder = true;
        do {
            int number = remain % 10;
            remain /= 10;
            numbers.push_back(number);

            if (isInOrder) {
                isInOrder = number < previousNumber;
                previousNumber = number;
            }
        } while (remain);

        if (isInOrder) {
            cout << -1 << endl;
            continue;
        }

        int replaceIndexes[2]{-1};
        const int size = static_cast<int>(numbers.size());
        for (int i = size - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if (numbers[i] > numbers[j]) {
                    replaceIndexes[0] = i;

                    if (numbers[j] > replaceIndexes[1])
                        replaceIndexes[1] = j;
                }
            }

            if (replaceIndexes[0] != -1 && replaceIndexes[1] != -1) {
                const int temp = numbers[replaceIndexes[0]];
                numbers[replaceIndexes[0]] = numbers[replaceIndexes[1]];
                numbers[replaceIndexes[1]] = temp;
                break;
            }

            replaceIndexes[0] = -1;
        }

        int base = 1;
        int newNumber = 0;
        for (const auto number: numbers) {
            newNumber += number * base;
            base *= 10;
        }
        cout << newNumber << endl;
    };

    return 0;
}
