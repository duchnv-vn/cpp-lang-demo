#include <iostream>
#include <string>
using namespace std;

int maxRemovedLength(const string& s) {
    int oneCount = 0;
    int zeroWaiting = 0;
    int totalRemoved = 0;

    for (char ch : s) {
        if (ch == '1') {
            oneCount++;
        } else if (ch == '0') {
            if (oneCount > 0) {
                zeroWaiting++;
                if (zeroWaiting == 2) {
                    // We've found a subsequence "100"
                    totalRemoved += 3;
                    oneCount--;
                    zeroWaiting = 0;
                }
            }
        }
    }

    return totalRemoved;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To consume the newline after the number of test cases

    while (T--) {
        string s;
        getline(cin, s);
        cout << maxRemovedLength(s) << endl;
    }

    return 0;
}
