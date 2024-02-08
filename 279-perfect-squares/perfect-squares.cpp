class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
    
    // Base case: 0 requires 0 perfect squares
    dp[0] = 0;
    
    // Iterate through all numbers from 1 to n
    for (int i = 1; i <= n; ++i) {
        // Check all possible perfect squares smaller than or equal to i
        for (int j = 1; j * j <= i; ++j) {
            // Update dp[i] with the minimum of current value and 1 + dp[i - j*j]
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }
    
    return dp[n];
    }
};