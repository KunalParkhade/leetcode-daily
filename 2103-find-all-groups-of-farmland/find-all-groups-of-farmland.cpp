class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size(), false));
        vector<vector<int>> ans;
        
        for (int row1 = 0; row1 < land.size(); row1++) {
            for (int col1 = 0; col1 < land[0].size(); col1++) {
                if (land[row1][col1] && !visited[row1][col1]) {
                    queue<pair<int, int>> q;
                    q.push({row1, col1});
                    visited[row1][col1] = true;
                    
                    pair<int, int> last = BFS(q, land, visited, row1, col1);
                    ans.push_back({row1, col1, last.first, last.second});
                }
            }
        }
        
        return ans;
    }
private:    
    // The four directions in which traversal will be done.
    int dirs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    // Returns true if the coordinate is within the boundary of the matrix.
    bool isWithinFarm(int x, int y, int N, int M) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
    
    pair<int, int> BFS(queue<pair<int, int>> q, vector<vector<int>>& land,
        vector<vector<bool>>& visited, int x, int y) {
        pair<int, int> curr;
        
        while (!q.empty()) {
            curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;
            
            for (auto dir : dirs) {
                // Neighbor cell coordinates.
                int newX = x + dir[0], newY = y + dir[1];

                // If the neighbor is within the matrix and is a farmland cell and not visited yet.
                if (isWithinFarm(newX, newY, land.size(), land[0].size()) && !visited[newX][newY]
                        && land[newX][newY]) {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        
        return curr;
    }
};