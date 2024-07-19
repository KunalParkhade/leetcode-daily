class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        if (n == 0)
            return ans; // Check for empty matrix

        int m = matrix[0].size();
        if (m == 0)
            return ans; // Check for empty rows

        vector<int> rowMin(n, INT_MAX);
        vector<int> colMax(m, INT_MIN);

        // Find minimum element in each row
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
            }
        }

        // Find maximum element in each column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                colMax[i] = max(colMax[i], matrix[j][i]);
            }
        }

        // Find lucky numbers
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};