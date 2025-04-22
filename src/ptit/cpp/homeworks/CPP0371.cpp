#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;

    string newS;
    const int letter_size = 6;
    char letters[letter_size] = {'A', 'E', 'I', 'O', 'U', 'Y'};
    for (int i = 0; i < S.length(); i++) {
        bool isInvalid = false;
        for (const char letter: letters) {
            if (S[i] == letter || S[i] == (letter + 32)) {
                isInvalid = true;
                break;
            }
        }

        if (!isInvalid) {
            newS += '.';
            newS += (S[i] < 97 ? static_cast<char>(S[i] + 32) : S[i]);
        }
    }

    cout << newS << endl;

    return 0;
}
