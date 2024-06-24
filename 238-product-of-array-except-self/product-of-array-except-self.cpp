class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);

        // STep 1: Calculate the prefix product
        for(int i=1;i<nums.size();i++){
            ans[i]=ans[i-1]*nums[i-1];
        }

        //Step 2: Calculate the suffix product
        int suffix=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]*=suffix;
            suffix*=nums[i];    //Updating suffix with next number
        }

        return ans;
    }
};