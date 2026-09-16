class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        // dp[i][j]: ways to place j segments among first i points
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // Base case: 0 segments can be formed in 1 way (empty set)
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= k; j++) {
            long long prefix_sum = 0;
            for (int i = 2; i <= n; i++) {
                // Add dp[i-1][j-1] to the prefix sum of available starting points
                prefix_sum = (prefix_sum + dp[i - 1][j - 1]) % MOD;

                // Option 1: Don't end a segment at point i -> dp[i-1][j]
                // Option 2: End a segment at point i -> prefix_sum
                dp[i][j] = (dp[i - 1][j] + prefix_sum) % MOD;
            }
        }

        return dp[n][k];
    }
};