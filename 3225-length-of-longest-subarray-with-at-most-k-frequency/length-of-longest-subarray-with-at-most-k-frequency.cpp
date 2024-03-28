class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int max_right=0, left=-1;
        unordered_map<int,int> mp;
        for(int right=0;right<n;right++){
            mp[nums[right]]++;
            while(mp[nums[right]]>k){
                left++;
                mp[nums[left]]--;
            }
            max_right=max(max_right,right-left);
        }
        return max_right;
    }
};