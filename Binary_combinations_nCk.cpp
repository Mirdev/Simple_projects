// Prints all n-digit binary numbers that contain exactly k ones.

#include <iostream>
using namespace std;

int main() {
    int bin[10] = {0}, n, k, i, j, count = 0;

    // Input: n (0 ≤ n ≤ 10)
    while (true) {
        cout << "Enter a non-negative integer n (0~10): ";
        cin >> n;
        if (n >= 0 && n <= 10) break;
        else cout << "n must be between 0 and 10.\n";
    }

    // Input: k (0 ≤ k ≤ n)
    while (true) {
        cout << "Enter a non-negative integer k (k ≤ n): ";
        cin >> k;
        if (k >= 0 && k <= n) break;
        else cout << "k must be between 0 and n.\n";
    }

    // Generate all binary numbers of length n
    for (i = 0; i < (1 << n); i++) {
        count = 0;
        for (j = 0; j < n; j++) {
            bin[j] = (i >> j) & 1;
            if (bin[j] == 1) count++;
        }

        // Print only those with exactly k ones
        if (count == k) {
            for (j = n - 1; j >= 0; j--) {
                cout << bin[j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
