#include <iostream>
using namespace std;

int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return -1;

    while (a > 1) {
        if (m == 0) return -1;
        q = a / m;
        t = m;

        m = a % m;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (a != 1) return -1;

    if (x1 < 0) x1 += m0;
    return x1;
}

int main() {
    cout << mod_inverse(3, 7);
    return 0;
}
