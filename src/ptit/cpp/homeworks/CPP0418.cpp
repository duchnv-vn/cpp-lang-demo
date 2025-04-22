#include <iostream>
#include <vector>
using namespace std;

void findUnionAndIntersection(int A[], int n, int B[], int m) {
    vector<int> union_arr, intersection_arr;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (A[i] < B[j]) {
            if (union_arr.empty() || union_arr.back() != A[i])
                union_arr.push_back(A[i]);
            i++;
        } else if (A[i] > B[j]) {
            if (union_arr.empty() || union_arr.back() != B[j])
                union_arr.push_back(B[j]);
            j++;
        } else { // A[i] == B[j], common element
            if (union_arr.empty() || union_arr.back() != A[i])
                union_arr.push_back(A[i]);
            intersection_arr.push_back(A[i]);
            i++;
            j++;
        }
    }

    // Add remaining elements from A
    while (i < n) {
        if (union_arr.empty() || union_arr.back() != A[i])
            union_arr.push_back(A[i]);
        i++;
    }

    // Add remaining elements from B
    while (j < m) {
        if (union_arr.empty() || union_arr.back() != B[j])
            union_arr.push_back(B[j]);
        j++;
    }

    // Print union
    for (int num : union_arr)
        cout << num << " ";
    cout << endl;

    // Print intersection
    if (intersection_arr.empty())
        cout << endl;
    else {
        for (int num : intersection_arr)
            cout << num << " ";
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        int A[n], B[m];
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < m; i++) cin >> B[i];

        findUnionAndIntersection(A, n, B, m);
    }

    return 0;
}
