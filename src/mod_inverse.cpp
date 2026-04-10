#include <iostream>
using namespace std;

// gcd
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// extended euclid
int extended_euclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = extended_euclid(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

// 👉 BẠN PHẢI VIẾT HÀM NÀY
int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_euclid(a, m, x, y);

    if (g != 1) {
        return -1; // không tồn tại
    }

    return (x % m + m) % m;
}

// test
int main() {
    cout << "mod_inverse(3,7) = " << mod_inverse(3,7) << endl;
    cout << "mod_inverse(6,9) = " << mod_inverse(6,9) << endl;
    return 0;
}
