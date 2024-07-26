class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& dp,
             vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (dp[row][col] != 0)      //Remembering the result if already computed
            return dp[row][col];

        int currMax = 1;

        // These arrays are used to get row and column numbers of 4 neighbors of
        // a given cell
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        // Explore 4 neighbors (up, down, left, right)
        for (int i = 0; i < 4; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];

            // Check if the new cell is within bounds and  and not
            // visited
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && matrix[newRow][newCol] > matrix[row][col]) {
                currMax = max(currMax, 1 + bfs(newRow, newCol, dp, matrix));
            }
        }
        dp[row][col] = currMax;
        return currMax;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(n == 0 || m == 0){
            return 0;
        }
        vector<vector<int>> dpMemo(m, vector<int>(n, 0));

        int maxLength = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                maxLength = max(maxLength, bfs(row, col, dpMemo, matrix));
            }
        }

        return maxLength;
    }
};