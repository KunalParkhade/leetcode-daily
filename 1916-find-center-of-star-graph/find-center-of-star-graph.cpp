class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> fEdge = edges[0];
        vector<int> sEdge = edges[1];

        if(fEdge[0] == sEdge[0] || fEdge[0] == sEdge[1]){
            return fEdge[0];
        }
        else{
            return fEdge[1];
        }
    }
};