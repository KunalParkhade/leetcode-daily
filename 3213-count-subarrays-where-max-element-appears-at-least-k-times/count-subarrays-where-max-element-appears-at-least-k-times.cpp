class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement=*max_element(nums.begin(),nums.end());
        long long count = 0, left=0;

        for(int right=0;right<nums.size();right++){
            if(nums[right]==maxElement){
                k--;
            }
            while(!k){
                if(nums[left]==maxElement){
                    k++;
                }
                left++;
            }
            count+=left;
        }
        return count;
    }
};