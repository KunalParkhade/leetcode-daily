class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Create two arrays to track the count of incoming and outgoing trusts for each person
        vector<int> incoming(n + 1, 0);
        vector<int> outgoing(n + 1, 0);
        
        // Iterate through the trust relationships and update the counts
        for (const auto& pair : trust) {
            int a = pair[0];
            int b = pair[1];
            outgoing[a]++;
            incoming[b]++;
        }
        
        // Find the person who satisfies properties 1 and 2
        for (int i = 1; i <= n; ++i) {
            if (incoming[i] == n - 1 && outgoing[i] == 0) {
                return i; // Found the town judge
            }
        }
        
        return -1; // Town judge does not exist
    }
};