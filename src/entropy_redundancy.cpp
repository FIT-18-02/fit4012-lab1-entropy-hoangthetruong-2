#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double calculate_entropy(const vector<double>& probs) {
    double entropy = 0.0;
    for (double p : probs) {
        if (p > 0) {
            entropy -= p * log2(p);
        }
    }
    return entropy;
}

double calculate_redundancy(const vector<double>& probs) {
    double entropy = calculate_entropy(probs);
    double max_entropy = log2(probs.size());
    return max_entropy - entropy;
}

int main() {
    vector<double> probs = {0.5, 0.25, 0.25};
    cout << "Entropy: " << calculate_entropy(probs) << endl;
    cout << "Redundancy: " << calculate_redundancy(probs) << endl;
    return 0;
}
