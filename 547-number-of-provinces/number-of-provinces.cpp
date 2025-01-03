class Solution {
private:
    void dfs(int node, vector<bool>& vis, vector<int> adjLs[]){
        vis[node]=true;

        for(auto it:adjLs[node]){
            if(!vis[it]){
                dfs(it, vis, adjLs);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        
        vector<int> adjLs[V];
        // to change adjacency matrix to adj list
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int cnt=0;
        vector<bool> vis(V, false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, adjLs);
            }
        }

        return cnt;
    }
};