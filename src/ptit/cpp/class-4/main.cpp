/*
 * Toán tử chồng lấn (unary, binary operators)
 */

#include <iostream>
using namespace std;

class complex {
public:
    double re, im;

    complex(const double r, const double i): re{r}, im{i} {
    }

    complex operator+(const complex comp2) const {
        return complex{re + comp2.re, im + comp2.im};
    }
};

int main() {
    const complex comp1{1.2, 0.5};
    const complex comp2{2.9, 3.3};

    const auto comp3 = comp1 + comp2;
    cout << "Real number: " << comp3.re << endl;
    cout << "Imagination number: " << comp3.im << endl;
}
