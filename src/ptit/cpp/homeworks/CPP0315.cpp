#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void findLargestSmaller(string &N) {
    int len = N.length();
    int idx1 = -1, idx2 = -1;

    // Step 1: Find the rightmost position where a swap is possible
    for (int i = len - 2; i >= 0; i--) {
        if (N[i] > N[i + 1]) {
            idx1 = i;
            break;
        }
    }

    // If no such index is found, it's already the smallest permutation
    if (idx1 == -1) {
        cout << "-1\n";
        return;
    }

    // Step 2: Find the largest number smaller than N[idx1] to its right
    for (int i = len - 1; i > idx1; i--) {
        if (N[i] < N[idx1]) {
            if (idx2 == -1 || N[i] > N[idx2]) {
                idx2 = i;
            }
        }
    }

    // Step 3: Swap the digits
    swap(N[idx1], N[idx2]);

    // Step 4: If the resulting number has a leading zero, print -1
    if (N[0] == '0') {
        cout << "-1\n";
    } else {
        cout << N << "\n";
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string N;
        cin >> N;
        findLargestSmaller(N);
    }

    return 0;
}
