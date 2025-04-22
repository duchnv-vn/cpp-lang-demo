#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string S;
        cin >> S;

        int total = 0;
        string numStr;
        for (int i = 0; i < S.length(); i++) {
            if (isdigit(S[i])) {
                numStr += S[i];
            } else {
                if (!numStr.empty()) {
                    total += stoi(numStr);
                    numStr = "";
                }
            }
        }
        if (!numStr.empty()) total += stoi(numStr);

        cout << total << endl;
    }

    return 0;
}
