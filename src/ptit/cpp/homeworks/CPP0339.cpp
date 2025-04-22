#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string S;
        cin >> S;

        int count = 0;
        const int len = S.length();
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                if (S[i] == S[j])count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
