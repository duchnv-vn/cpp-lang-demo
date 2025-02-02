#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        int N, M;
        cin >> N >> M;

        int A[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }

        int B[N][M];
        // bool hasOne = false;
        for (int i = 0; i < N; i++) {
            // hasOne = false;

            for (int j = 0; j < M; j++) {
                if (A[i][j] == 0) {
                    if (B[i][j] != 1) B[i][j] = 0;
                } else {
                    // if (!hasOne) {
                    //     for (int c = 0; c < M; c++) {
                    //         B[i][c] = 1;
                    //     }
                    // }

                    for (int c = 0; c < M; c++) {
                        B[i][c] = 1;
                    }

                    for (int r = 0; r < N; r++) {
                        B[r][j] = 1;
                    }

                    // hasOne = true;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << B[i][j] << " ";
            }
            cout << endl;
        }
    }
}
