#include <iostream>
#include <vector>
using namespace std;

void rotateBoundary(vector<vector<int>>& A, int n, int m) {
    if (n == 1) { // Special case: Single row
        int last = A[0][m - 1];
        for (int j = m - 1; j > 0; j--) A[0][j] = A[0][j - 1];
        A[0][0] = last;
        return;
    }

    if (m == 1) { // Special case: Single column
        int last = A[n - 1][0];
        for (int i = n - 1; i > 0; i--) A[i][0] = A[i - 1][0];
        A[0][0] = last;
        return;
    }

    // Step 1: Extract boundary elements
    vector<int> boundary;

    // Top row (left to right)
    for (int j = 0; j < m; j++) boundary.push_back(A[0][j]);

    // Right column (top to bottom, excluding first element)
    for (int i = 1; i < n; i++) boundary.push_back(A[i][m - 1]);

    // Bottom row (right to left, if n > 1)
    if (n > 1) {
        for (int j = m - 2; j >= 0; j--) boundary.push_back(A[n - 1][j]);
    }

    // Left column (bottom to top, excluding first and last elements)
    if (m > 1) {
        for (int i = n - 2; i > 0; i--) boundary.push_back(A[i][0]);
    }

    // Step 2: Rotate boundary elements one step clockwise
    int last = boundary.back();
    boundary.pop_back();
    boundary.insert(boundary.begin(), last);

    // Step 3: Put rotated boundary back into the matrix
    int index = 0;

    // Top row (left to right)
    for (int j = 0; j < m; j++) A[0][j] = boundary[index++];

    // Right column (top to bottom, excluding first element)
    for (int i = 1; i < n; i++) A[i][m - 1] = boundary[index++];

    // Bottom row (right to left, if n > 1)
    if (n > 1) {
        for (int j = m - 2; j >= 0; j--) A[n - 1][j] = boundary[index++];
    }

    // Left column (bottom to top, excluding first and last elements)
    if (m > 1) {
        for (int i = n - 2; i > 0; i--) A[i][0] = boundary[index++];
    }
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> A(n, vector<int>(m));

        // Read input matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }

        // Rotate the boundary
        rotateBoundary(A, n, m);

        // Print rotated matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << A[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
