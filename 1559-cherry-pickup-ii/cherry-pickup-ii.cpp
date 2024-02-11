class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        dp[0][0][cols - 1] = grid[0][0] + grid[0][cols - 1];

        int maxCherries = 0;
        for (int row = 1; row < rows; ++row) {
            for (int posA = 0; posA < cols; ++posA) {
                for (int posB = posA + 1; posB < cols; ++posB) {
                    for (int offsetA = -1; offsetA <= 1; ++offsetA) {
                        for (int offsetB = -1; offsetB <= 1; ++offsetB) {
                            int nextPosA = posA + offsetA;
                            int nextPosB = posB + offsetB;
                            if (nextPosA >= 0 && nextPosA < cols && nextPosB >= 0 && nextPosB < cols) {
                                int prevMax = dp[row - 1][nextPosA][nextPosB];
                                if (prevMax != -1) {
                                    dp[row][posA][posB] = max(dp[row][posA][posB], prevMax + grid[row][posA] + (posA != posB ? grid[row][posB] : 0));
                                }
                            }
                        }
                    }
                    if (maxCherries < dp[row][posA][posB]) {
                        maxCherries = dp[row][posA][posB];
                    }
                }
            }
        }
        return maxCherries;
    }
};