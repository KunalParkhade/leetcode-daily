class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, pair<int, int>> numToPos;
        vector<int> rowCount(m), colCount(n);
        // Step 1: Fill Position of number
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                int val = mat[row][col];
                numToPos[val] = {row, col};
            }
        }

        // Step 2: Retrieve positions
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            auto [row, col] = numToPos[num];
            mat[row][col] = -mat[row][col];

            // Increment the count for the corresponding row and column
            rowCount[row]++;
            colCount[col]++;

            if (rowCount[row] == n || colCount[col] == m) {
                return i;
            }
        }

        return -1;
    }

    // private:
    //     bool checkRow(int row, vector<vector<int>>& mat){
    //         for(int col=0;col<mat[0].size();col++){
    //             if(mat[row][col]>0){
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }

    //     bool checkCol(int col, vector<vector<int>>& mat){
    //         for(int row=0;row<mat.size();row++){
    //             if(mat[row][col]>0){
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }
};