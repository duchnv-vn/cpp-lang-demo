#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

void processFile(const string& filename, set<string>& wordSet) {
    ifstream inFile(filename);
    string line, word;
    // Đọc từng dòng trong file
    while (getline(inFile, line)) {
        stringstream ss(line);
        // Đọc từng từ trong dòng
        while (ss >> word) {
            // Chuyển từ thành chữ thường
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            // Thêm từ vào set
            wordSet.insert(word);
        }
    }
}

int main() {
    set<string> words1, words2;

    // Xử lý file DATA1.in và DATA2.in
    processFile("DATA1.in", words1);
    processFile("DATA2.in", words2);

    // Tính hợp của hai tập từ
    set<string> unionSet;
    set_union(words1.begin(), words1.end(), words2.begin(), words2.end(),
              inserter(unionSet, unionSet.begin()));

    // Tính giao của hai tập từ
    set<string> intersectionSet;
    set_intersection(words1.begin(), words1.end(), words2.begin(), words2.end(),
                     inserter(intersectionSet, intersectionSet.begin()));

    // In ra hợp của hai tập
    cout << "HOP: ";
    for (const auto& w : unionSet) {
        cout << w << " ";
    }
    cout << endl;

    // In ra giao của hai tập
    cout << "GIAO: ";
    for (const auto& w : intersectionSet) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}
