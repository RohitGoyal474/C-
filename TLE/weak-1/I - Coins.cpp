#include <iostream>
#include <vector>
#include <iomanip> // For setting precision
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> arr(n);
    for (auto &x : arr) cin >> x;

    // DP table: dp[i][j] = probability of getting exactly j heads with first i coins
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));

    // Base case: 0 heads when no coins are considered
    dp[n][0] = 1.0;

    // Bottom-up DP
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n; j++) {
            double head = (j > 0) ? dp[i + 1][j - 1] * arr[i] : 0.0;
            double tail = dp[i + 1][j] * (1.0 - arr[i]);
            dp[i][j] = head + tail;
        }
    }

    // Sum up probabilities for more heads than tails
    int h = (n / 2) + 1;
    double ans = 0.0;
    for (int i = h; i <= n; i++) {
        ans += dp[0][i];
    }

    // Print the answer with high precision
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}