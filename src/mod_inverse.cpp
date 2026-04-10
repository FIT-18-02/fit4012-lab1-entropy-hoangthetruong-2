#include <iostream>

// Đã có sẵn
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int extended_euclid(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

// ==================== HOÀN THIỆN HÀM NÀY ====================
int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_euclid(a, m, x, y);
    
    if (g != 1) {
        return -1;        // Không tồn tại nghịch đảo
    }
    // Làm cho x dương
    return (x % m + m) % m;
}
// ===========================================================

int main() {
    // Test cases
    std::pair<int,int> tests[] = {
        {3, 7}, {6, 9}, {5, 11}, {7, 26}, {4, 9}, {10, 17}
    };

    for (auto& p : tests) {
        int a = p.first, m = p.second;
        int inv = mod_inverse(a, m);
        std::cout << "mod_inverse(" << a << ", " << m << ") = ";
        if (inv == -1)
            std::cout << "Không tồn tại\n";
        else
            std::cout << inv << "\n";
    }
    return 0;
}
