#include <iostream>
#include <map>
#include <cmath>
#include <set>
using namespace std;

// Hàm tính entropy
double calculate_entropy(const string &input) {
    map<char, int> freq;

    for (char c : input) {
        freq[c]++;
    }

    double entropy = 0.0;
    int n = input.length();

    for (auto &p : freq) {
        double prob = (double)p.second / n;
        entropy -= prob * log2(prob);
    }

    return entropy;
}

// 👉 BẠN PHẢI VIẾT HÀM NÀY
double calculate_redundancy(const string &input) {
    double H = calculate_entropy(input);

    set<char> unique_chars(input.begin(), input.end());
    int alphabet_size = unique_chars.size();

    if (alphabet_size <= 1) return 0.0;

    double H_max = log2(alphabet_size);

    return 1.0 - (H / H_max);
}

// test nhanh
int main() {
    string s1 = "aaaa";
    string s2 = "abcd";
    string s3 = "aabbcc";

    cout << "Input: " << s1 << endl;
    cout << "Entropy: " << calculate_entropy(s1) << endl;
    cout << "Redundancy: " << calculate_redundancy(s1) << endl;

    cout << "\nInput: " << s2 << endl;
    cout << "Entropy: " << calculate_entropy(s2) << endl;
    cout << "Redundancy: " << calculate_redundancy(s2) << endl;

    cout << "\nInput: " << s3 << endl;
    cout << "Entropy: " << calculate_entropy(s3) << endl;
    cout << "Redundancy: " << calculate_redundancy(s3) << endl;

    return 0;
}
