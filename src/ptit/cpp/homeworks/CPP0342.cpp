#include <iostream>
using namespace std;

void quickSort(string &str, const int left, const int right) {
    if (left >= right) return;

    int tempL = left, tempR = right;
    const auto pivot = str[(left + right) / 2];

    while (tempL <= tempR) {
        while (str[tempL] < pivot) tempL++;
        while (str[tempR] > pivot) tempR--;

        if (tempL <= tempR) {
            swap<char>(str[tempL], str[tempR]);
            tempL++;
            tempR--;
        }
    }

    if (left < tempR) quickSort(str, left, tempR);
    if (tempL < right) quickSort(str, tempL, right);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string S;
        cin >> S;

        string S_2;
        int total = 0;
        for (int i = 0; i < S.length(); i++) {
            if (isdigit(S[i])) {
                total += S[i] - '0';
            } else {
                S_2 += S[i];
            }
        }

        quickSort(S_2, 0, S_2.length() - 1);

        cout << S_2 << total << endl;
    }


    return 0;
}
