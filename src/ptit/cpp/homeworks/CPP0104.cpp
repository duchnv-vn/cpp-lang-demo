#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    long long sum = 0;
    long long factorial = 1;

    for (int i = 1; i <= N; i++) {
        factorial *= i;
        sum += factorial;
    }

    cout << sum << endl;
}
