class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp {0}; // Static vector to store precomputed values
        
        // Ensure the vector has enough precomputed values
        while (dp.size() <= n) {
            int m = dp.size();
            int squares = INT_MAX;
            // Iterate through perfect squares smaller than or equal to m
            for (int i = 1; i * i <= m; ++i) {
                squares = min(squares, 1 + dp[m - i * i]);
            }
            dp.push_back(squares); // Store the optimal result for m
        }
        
        return dp[n];
    }
};
