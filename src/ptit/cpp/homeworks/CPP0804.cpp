#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ifstream inFile("VANBAN.in");
    set<string> words;  // Dùng set để lưu các từ, tự động sắp xếp theo thứ tự từ điển
    string line, word;

    // Đọc từng dòng trong file
    while (getline(inFile, line)) {
        stringstream ss(line);
        // Đọc từng từ trong dòng
        while (ss >> word) {
            // Chuyển từ thành chữ thường
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            // Thêm từ vào set
            words.insert(word);
        }
    }

    // In ra các từ khác nhau theo thứ tự từ điển
    for (const auto& w : words) {
        cout << w << endl;
    }

    return 0;
}
