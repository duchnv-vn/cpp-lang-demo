#include <iostream>
using namespace std;

class Fraction {
    long long numerator;
    long long denominator;

    static long long gcd(long long a, long long b) {
        while (b != 0) {
            const long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    Fraction(const long long n, const long long d) {
        const long long g = gcd(n, d);
        numerator = n / g;
        denominator = d / g;
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    long long n, d;
    cin >> n >> d;

    const Fraction fraction{n, d};
    fraction.print();
    return 0;
}
