// cpp program for knapsack using dynamic programming 
#include <iostream>
#include <vector>

using namespace std;

void printSelectedItems(const vector<vector<int>>& dp, const vector<int>& weights, int n, int w) {
    int i = n;
    int j = w;

    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            cout << "Item " << i << " (weight: " << weights[i - 1] << ")" << endl;
            j -= weights[i - 1];
        }
        i--;
    }
}

int knapsack(int capacity, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Selected items:\n";
    printSelectedItems(dp, weights, n, capacity);

    return dp[n][capacity];
}

int main() {
    int capacity, n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int maxTotalValue = knapsack(capacity, weights, values);
    cout << "Maximum total value that can be obtained: " << maxTotalValue << endl;

    return 0;
}
