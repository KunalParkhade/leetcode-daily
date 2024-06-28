class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n, 0);

        for(vector<int> edge: roads){
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        sort(degree.begin(), degree.end());

        long long val=1;
        long long total=0;

        for(long long d : degree){
            total += d*val;
            val++;
        }

        return total;
    }
};