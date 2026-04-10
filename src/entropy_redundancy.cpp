#include <iostream>
#include <map>
#include <string>
#include <cmath>

double calculate_entropy(const std::string& s) {
    if (s.empty()) return 0.0;
    
    std::map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    
    double entropy = 0.0;
    int n = s.length();
    
    for (auto& p : freq) {
        double p_i = static_cast<double>(p.second) / n;
        entropy -= p_i * log2(p_i);
    }
    return entropy;
}

// ==================== BỔ SUNG HÀM NÀY ====================
double calculate_redundancy(const std::string& s) {
    if (s.empty()) return 0.0;
    
    double H = calculate_entropy(s);
    int alphabet_size = 256;                    // giả sử ký tự ASCII
    double H_max = log2(alphabet_size);
    
    return 1.0 - (H / H_max);                   // Redundancy
}
// =======================================================

int main() {
    std::string tests[] = {
        "aaaaaaa",           // entropy thấp, redundancy cao
        "abcd",              // entropy cao
        "aabbccdd",
        "hello world",
        "this is a test string for entropy calculation",
        "Nguyen Van A 123456"
    };

    for (const auto& str : tests) {
        double H = calculate_entropy(str);
        double R = calculate_redundancy(str);
        
        std::cout << "String: \"" << str << "\"\n";
        std::cout << "  Entropy     = " << H << "\n";
        std::cout << "  Redundancy  = " << R << "\n\n";
    }
    return 0;
}
