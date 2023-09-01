//cpp program to code calculate binomial Coefficient using dynamic programming @ 01-09-2023
#include <iostream>
#include <vector>

using namespace std;

int binomialCoefficient(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= min(i, k); ++j) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;
    cout << "Enter the values of n and k: ";
    cin >> n >> k;

    if (k >= 0 && k <= n) {
        int coefficient = binomialCoefficient(n, k);
        cout << "Binomial Coefficient C(" << n << ", " << k << ") = " << coefficient << endl;
    } else {
        cout << "Invalid input. k must be between 0 and n." << endl;
    }

    return 0;
}
