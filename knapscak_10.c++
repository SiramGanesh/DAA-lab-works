#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve 0/1 Knapsack problem
int knapsack(int W, vector<int> weight, vector<int> value, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[][] in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weight[i - 1] <= w) {
                // Include or exclude the current item
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]], // include
                    dp[i - 1][w] // exclude
                );
            } else {
                dp[i][w] = dp[i - 1][w]; // can't include this item
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n; // number of items
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> value(n), weight(n);
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) cin >> value[i];
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) cin >> weight[i];

    int W; // maximum capacity of knapsack
    cout << "Enter maximum capacity of knapsack: ";
    cin >> W;

    cout << "Maximum value that can be obtained: " << knapsack(W, weight, value, n) << endl;

    return 0;
}
