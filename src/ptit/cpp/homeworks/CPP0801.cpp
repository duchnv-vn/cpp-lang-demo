#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("PTIT.in");
    ofstream outputFile("PTIT.out");

    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
