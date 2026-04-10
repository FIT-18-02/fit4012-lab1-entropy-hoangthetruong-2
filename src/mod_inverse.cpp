#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

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

int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_euclid(a, m, x, y);

    if (g != 1) return -1;

    return (x % m + m) % m;
}

// ❗ BẮT BUỘC PHẢI CÓ MAIN (lỗi của bạn)
int main() {
    cout << mod_inverse(3,7) << endl;
    cout << mod_inverse(6,9) << endl;
    return 0;
}
