#include <iostream>
#include <vector>
#include <array>
using namespace std;

#define K 3

void add_combination(vector<array<int,K> > &combinations, const int combination[K]) {
    array<int,K> clone_combination{};
    for (int i = 0; i < K; i++) clone_combination[i] = combination[i];
    combinations.push_back(clone_combination);
}

void find_combination(vector<array<int,K> > &combinations, int combination[K], const int curr_idx) {
    if (curr_idx == K) {
        add_combination(combinations, combination);
        return;
    }

    for (int i = 1; i <= K * K; i++) {
        bool is_unique = true;
        for (int j = 0; j < curr_idx; j++) {
            if (combination[j] == i) {
                is_unique = false;
                break;
            }
        }

        if (is_unique) {
            combination[curr_idx] = i;
            find_combination(combinations, combination, curr_idx + 1);
        }
    }
}


int main() {
    vector<array<int,K> > combinations;
    int temp_combination[K];
    find_combination(combinations, temp_combination, 0);

    int min_sum = 0, max_sum = 0;
    for (int i = 0; i < K; i++) {
        min_sum += i + 1;
        max_sum += K * K - i;
    }

    const int sum_count = max_sum - min_sum + 1;
    vector<array<int,K> > combinations_by_sum[sum_count];
    for (const auto com: combinations) {
        int sum = 0;
        for (int i = 0; i < K; i++) sum += com[i];
        combinations_by_sum[sum - min_sum].push_back(com);
    }

    // cout << "Sum count: " << sum_count << endl;
    for (int i = 0; i < sum_count; i++) {
        if (combinations_by_sum[i].size() < 8) continue;

        for (const auto com: combinations_by_sum[i]) {
            cout << com[0] << "," << com[1] << "," << com[2] << endl;
        }

        break;
        // cout << "Sum: " << i + min_sum << " | " << "Size: " << combinations_by_sum[i].size() << endl;
    }
}
