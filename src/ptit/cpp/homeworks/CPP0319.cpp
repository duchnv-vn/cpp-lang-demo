#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void findSmallestAndLargest(const int m, const int s) {
    if ((s == 0 && m > 1) || s > 9 * m) {
        cout << "-1 -1" << endl;
        return;
    }

    string largest;
    int sum = s;
    for (int i = 0; i < m; i++) {
        const int digit = min(9, sum);
        largest += static_cast<char>('0' + digit);
        sum -= digit;
    }

    string smallest = largest;
    reverse(smallest.begin(), smallest.end());

    if (smallest[0] == '0') {
        for (int i = 0; i < m; i++) {
            if (smallest[i] > '0') {
                smallest[i]--;
                smallest[0] = '1';
                break;
            }
        }
    }

    cout << smallest << " " << largest << endl;
}

int main() {
    int m, s;
    cin >> m >> s;
    findSmallestAndLargest(m, s);
    return 0;
}
