#include <iostream>
using namespace std;

int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, m;
    cout << "Enter number and modulus: ";
    cin >> a >> m;

    int x, y;
    int gcd = extendedGCD(a, m, x, y);

    if (gcd != 1) {
        cout << "Multiplicative inverse does not exist.";
    } else {
        int inverse = (x % m + m) % m;
        cout << "Multiplicative inverse = " << inverse;
    }

    return 0;
}