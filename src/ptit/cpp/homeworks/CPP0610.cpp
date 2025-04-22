#include <iostream>
using namespace std;

class Fraction {
    static long long gcd(long long a, long long b) {
        while (b != 0) {
            const long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    long long numerator;
    long long denominator;

    Fraction(const long long n, const long long d) {
        const long long g = gcd(n, d);
        numerator = n / g;
        denominator = d / g;
    }

    Fraction operator+(Fraction const &fraction) const {
        const auto new_n = numerator * fraction.denominator + fraction.numerator * denominator;
        const auto new_d = fraction.denominator * denominator;

        return Fraction{new_n, new_d};
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    long long n_1, d_1, n_2, d_2;
    cin >> n_1 >> d_1 >> n_2 >> d_2;

    const Fraction fraction_1{n_1, d_1};
    const Fraction fraction_2{n_2, d_2};
    const auto fraction_3 = fraction_1 + fraction_2;

    fraction_3.print();

    return 0;
}
