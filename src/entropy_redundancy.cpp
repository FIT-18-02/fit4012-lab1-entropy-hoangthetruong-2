#include <bits/stdc++.h>
using namespace std;

// Hàm tính Entropy (Shannon Entropy) theo công thức H = -Σ p_i * log2(p_i)
double calculate_entropy(const string& s) {
    if (s.empty()) return 0.0;

    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    double entropy = 0.0;
    int n = s.length();
    for (auto& p : freq) {
        double prob = static_cast<double>(p.second) / n;
        if (prob > 0) {
            entropy -= prob * log2(prob);
        }
    }
    return entropy;
}

// Hàm tính Redundancy = 1 - (H / H_max)
// H_max = log2(số ký tự duy nhất trong chuỗi)
double calculate_redundancy(const string& s) {
    if (s.empty()) return 0.0;

    double H = calculate_entropy(s);

    // Tính số ký tự duy nhất
    unordered_set<char> unique_chars(s.begin(), s.end());
    int alphabet_size = unique_chars.size();

    if (alphabet_size <= 1) return 1.0;  // redundancy = 100% nếu chỉ 1 ký tự

    double H_max = log2(alphabet_size);
    return 1.0 - (H / H_max);
}

int main() {
    vector<string> test_strings = {
        "aaaa",                    // lặp hoàn toàn
        "abcd",                    // đa dạng
        "aabbccdd",                // lặp từng cặp
        "hello world",             // có khoảng trắng và lặp
        "this is a test string with some repetition"  // chuỗi dài hơn
    };

    cout << "=== ENTROPY & REDUNDANCY CALCULATION ===\n\n";

    for (const auto& str : test_strings) {
        double h = calculate_entropy(str);
        double r = calculate_redundancy(str);

        cout << "Chuỗi: \"" << str << "\"" << endl;
        cout << "Độ dài: " << str.length() << endl;
        cout << "Entropy: " << fixed << setprecision(4) << h << " bits" << endl;
        cout << "Redundancy: " << fixed << setprecision(4) << (r * 100) << "%" << endl;
        cout << "----------------------------------------\n";
    }

    return 0;
}
