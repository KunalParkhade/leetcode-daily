class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n=nums.size();
        int prod=1,left=0;
        int count=0;

        for(int right=0;right<n;right++){
            prod*=nums[right];

            while(prod>=k && left<=right){
                prod/=nums[left];
                left++;
            }
            count+=(right-left+1);
        }
        return count;
    }
};