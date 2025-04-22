#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main() {
    ifstream inFile("DATA.in");
    map<int, int> freq;
    int x;

    while (inFile >> x) {
        freq[x]++;
    }

    for (const auto& [val, count] : freq) {
        cout << val << " " << count << endl;
    }

    return 0;
}
