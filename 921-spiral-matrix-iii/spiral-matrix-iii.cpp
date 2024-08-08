class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        vector<vector<int>> ans;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0, steps = 1;

        ans.push_back({rStart, cStart});

        while (ans.size() < rows * cols) {
            for (int i = 0; i < 2;
                 i++) { // Complete two directions at each iteration
                for (int j = 0; j < steps; j++) {
                    rStart += directions[dir][0];
                    cStart += directions[dir][1];
                    if (rStart >= 0 && rStart < rows && cStart >= 0 &&
                        cStart < cols) {
                        ans.push_back({rStart, cStart});
                    }
                }
                dir = (dir + 1) % 4; // Change direction
            }
            steps++;
        }

        return ans;
    }
};
