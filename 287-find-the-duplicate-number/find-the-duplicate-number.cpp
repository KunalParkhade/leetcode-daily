class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int a:nums){
            freq[a]++;
        }

        int repeat;

        for(auto &entry:freq){
            if(entry.second > 1){
                repeat = entry.first;
            }
        }

        return repeat;
    }
};