class Solution {
public:
    int Helper(int i, int j, vector<vector<int>>& grid,
               vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return grid[0][0];
        if (i < 0 || j < 0)
            return INT_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = INT_MAX, left = INT_MAX;
        if (i > 0) {
            up = grid[i][j] + Helper(i - 1, j, grid, dp);
        }
        if (j > 0) {
            left = grid[i][j] + Helper(i, j - 1, grid, dp);
        }

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[0][0];
                else {
                    int up = INT_MAX, left = INT_MAX;
                    if (i > 0) up = grid[i][j] + dp[i - 1][j];
                    if (j > 0) left = grid[i][j] + dp[i][j - 1];
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};