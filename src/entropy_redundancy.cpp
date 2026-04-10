#include <iostream>
#include <map>
#include <cmath>
#include <set>
using namespace std;

// Tính entropy
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

// 👉 BỔ SUNG HÀM NÀY
double calculate_redundancy(const string &input) {
    double H = calculate_entropy(input);

    set<char> unique_chars(input.begin(), input.end());
    int alphabet_size = unique_chars.size();

    if (alphabet_size <= 1) return 0.0;

    double H_max = log2(alphabet_size);

    return 1.0 - (H / H_max);
}
