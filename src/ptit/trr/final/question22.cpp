#include <iostream>
using namespace std;

// int main() {
//     const int min = 1000;
//     const int max = 5000;
//
//     int count = 0;
//     for (int i = min; i <= max; i++) {
//         if (i % 6 == 0 || i % 9 == 0) count++;
//     }
//
//     cout << "Total: " << count << endl;
//     return 0;
// }

int count(const int k, const int divisibleMaxNumber, const int divisibleMinNumber) {
    return (divisibleMaxNumber / k) - ((divisibleMinNumber - 1) / k);
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    const int min = 1000;
    const int max = 5000;

    int divisibleMaxNumber_6 = 0;
    int divisibleMinNumber_6 = 0;
    int divisibleMaxNumber_9 = 0;
    int divisibleMinNumber_9 = 0;
    int divisibleMaxNumber_6_and_9 = 0;
    int divisibleMinNumber_6_and_9 = 0;
    for (int i = 0; i <= (max - min); i++) {
        if (divisibleMinNumber_6 != 0 && divisibleMinNumber_9 != 0 && divisibleMaxNumber_6 != 0 && divisibleMaxNumber_9
            != 0 && divisibleMaxNumber_6_and_9 != 0 && divisibleMinNumber_6_and_9 != 0)
            break;

        const int frontNumber = min + i;
        const int rearNumber = max - i;

        if (divisibleMaxNumber_6 == 0 && rearNumber % 6 == 0) {
            divisibleMaxNumber_6 = rearNumber;
        }
        if (divisibleMinNumber_6 == 0 && frontNumber % 6 == 0) {
            divisibleMinNumber_6 = frontNumber;
        }

        if (divisibleMaxNumber_9 == 0 && rearNumber % 9 == 0) {
            divisibleMaxNumber_9 = rearNumber;
        }
        if (divisibleMinNumber_9 == 0 && frontNumber % 9 == 0) {
            divisibleMinNumber_9 = frontNumber;
        }

        if (divisibleMinNumber_6_and_9 == 0 && frontNumber % 6 == 0 && frontNumber % 9 == 0) {
            divisibleMinNumber_6_and_9 = frontNumber;
        }
        if (divisibleMaxNumber_6_and_9 == 0 && rearNumber % 6 == 0 && rearNumber % 9 == 0) {
            divisibleMaxNumber_6_and_9 = rearNumber;
        }
    }

    const int divisibleCount_6 = count(6, divisibleMaxNumber_6, divisibleMinNumber_6);
    const int divisibleCount_9 = count(9, divisibleMaxNumber_9, divisibleMinNumber_9);

    const int lcm = (6 * 9) / gcd(6, 9);
    const int divisibleCount_6_and_9 = count(lcm, divisibleMaxNumber_6_and_9,
                                             divisibleMinNumber_6_and_9);

    const int divisibleCount_6_or_9 = divisibleCount_6 + divisibleCount_9 - divisibleCount_6_and_9;
    cout << "Total: " << divisibleCount_6_or_9 << endl;

    return 0;
}
