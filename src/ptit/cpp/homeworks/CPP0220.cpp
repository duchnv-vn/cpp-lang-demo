#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        int N;
        cin >> N;

        int A[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> A[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == 0 || j == 0 || i == N - 1 || j == N - 1) {
                    cout << A[i][j] << " ";
                } else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
}
