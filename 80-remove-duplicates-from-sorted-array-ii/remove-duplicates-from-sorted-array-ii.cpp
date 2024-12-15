class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // unordered_map<int, int> count;
        // int k = 0;

        // for(int num:nums){
        //     count[num]++;
        //     if(count[num]<=2){
        //         nums[k] = num;
        //         k++;
        //     }
        // }

        int k = 2;

        if(nums.size()<=2) return nums.size();

        for(int i=2;i<nums.size();i++){
            if(nums[i]!=nums[k-2]){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};