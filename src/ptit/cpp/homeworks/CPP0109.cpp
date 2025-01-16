#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N % 2 != 0) return 0;

    const int min = static_cast<int>(pow(10, N - 1));
    const int max = min * 10;
    int countToEndPrint = 0;
    for (int j = min; j < max; j += 10) {
        for (int k = 0; k < 10; k++) {
            const int number = j + k;
            int tempNumber = j + k;

            int evenCount = 0;
            int oddCount = 0;
            while (tempNumber != 0) {
                (tempNumber % 10) % 2 == 0 ? evenCount++ : oddCount++;
                tempNumber /= 10;
            }

            if (evenCount == oddCount) {
                cout << number << " ";
                countToEndPrint++;
            }
        }

        if (countToEndPrint == 10) {
            countToEndPrint = 0;
            cout << endl;
        }
    }

    return 0;
}
