class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> dup;
        for(int i:nums){
            mp[i]++;
        }
        for(auto a:mp){
            if(a.second>1){
                dup.push_back(a.first);
            }
        }

        return dup;
    }
};