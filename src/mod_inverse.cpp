#include <bits/stdc++.h>
using namespace std;

// Hàm Euclidean algorithm (đã cho sẵn)
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Hàm Extended Euclidean algorithm (đã cho sẵn)
long long extended_euclid(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// Hoàn thiện hàm mod_inverse
// Trả về nghịch đảo modulo nếu tồn tại, ngược lại trả về -1
long long mod_inverse(long long a, long long m) {
    if (m <= 0) return -1;

    long long x, y;
    long long g = extended_euclid(a, m, x, y);

    if (g != 1) {
        return -1;  // Không tồn tại nghịch đảo modulo
    }

    // Đưa x về khoảng dương [0, m-1]
    return (x % m + m) % m;
}

int main() {
    cout << "=== MODULAR INVERSE ===\n\n";

    vector<pair<long long, long long>> tests = {
        {3, 7},
        {5, 11},
        {6, 9},
        {7, 26},
        {2, 5},
        {4, 7}
    };

    for (auto& p : tests) {
        long long a = p.first;
        long long m = p.second;
        long long inv = mod_inverse(a, m);

        cout << "mod_inverse(" << a << ", " << m << ") = ";
        if (inv == -1) {
            cout << "KHÔNG TỒN TẠI (gcd != 1)" << endl;
        } else {
            cout << inv << "  (kiểm tra: " << a << " * " << inv << " ≡ 1 mod " << m << ")" << endl;
        }
    }

    return 0;
}
