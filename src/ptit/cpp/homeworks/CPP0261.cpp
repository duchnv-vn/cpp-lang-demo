#include <iostream>
using namespace std;

void copy_coordinate(int combination[][2], const int *coordinate, const int i) {
    for (int j = 0; j < 2; j++)
        combination[i][j] = coordinate[j];
}

void coordinate_combination(int combination[][2], const int i, int *prev_coordinate, const int max_coordinate_point_val,
                            const int point_step) {
    int temp_idx = 1;
    while (prev_coordinate[temp_idx] == max_coordinate_point_val) temp_idx--;
    if (temp_idx >= 0) {
        prev_coordinate[temp_idx] += point_step;
        while (temp_idx < 1) prev_coordinate[++temp_idx] = 0;
        copy_coordinate(combination, prev_coordinate, i);
    }
}

int main() {
    int N, M;

    cin >> N;
    int A[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    cin >> M;
    const int total_B = M * M;
    int B[M][M];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            cin >> B[i][j];

    const int slide_num = N * N / total_B;
    int start_idx_coordinates_A[slide_num][2];
    const int max_start_coordinate = N - M;

    int temp_coordinate_A[2]{0, 0};
    copy_coordinate(start_idx_coordinates_A, temp_coordinate_A, 0);

    for (int i = 1; i < slide_num; i++)
        coordinate_combination(start_idx_coordinates_A, i, temp_coordinate_A, max_start_coordinate, M);

    int coordinates_B[total_B][2];
    int temp_coordinate_B[2]{0, 0};
    copy_coordinate(coordinates_B, temp_coordinate_B, 0);
    for (int i = 1; i < total_B; i++)
        coordinate_combination(coordinates_B, i, temp_coordinate_B, M - 1, 1);

    for (int i = 0; i < slide_num; i++) {
        const auto start_idx_coordinate_A = start_idx_coordinates_A[i];
        for (int j = 0; j < total_B; j++) {
            const auto coordinate_B = coordinates_B[j];
            A[start_idx_coordinate_A[0] + coordinate_B[0]][start_idx_coordinate_A[1] + coordinate_B[1]] *=
                    B[coordinate_B[0]][coordinate_B[1]];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << " ";

        cout << endl;
    }
}
