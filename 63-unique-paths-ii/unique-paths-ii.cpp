class Solution {
public:
    // Memo
    int helper(int i, int j, vector<vector<int>>& obstacleGrid,
               vector<vector<int>>& dp) {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
            return 0;

        if (i == 0 && j == 0)
            return 1;

        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = helper(i - 1, j, obstacleGrid, dp);
        int left = helper(i, j - 1, obstacleGrid, dp);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // Space Optimization
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    curr[j] = 0;
                else if (i == 0 && j == 0)
                    curr[j] = 1;
                else {
                    int up = 0, left = 0;
                    if (i > 0) {
                        up = prev[j];
                    }
                    if (j > 0) {
                        left = curr[j - 1];
                    }
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n - 1];
        // Tabulation
        //  int dp[m][n];

        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (obstacleGrid[i][j] == 1)
        //             dp[i][j] = 0;
        //         else if (i == 0 && j == 0)
        //             dp[i][j] = 1;
        //         else {
        //             int up = 0, left = 0;
        //             if (i > 0)
        //                 up = dp[i - 1][j];
        //             if (j > 0)
        //                 left = dp[i][j - 1];
        //             dp[i][j] = up + left;
        //         }
        //     }
        // }
        // return dp[m - 1][n - 1];
    }
};