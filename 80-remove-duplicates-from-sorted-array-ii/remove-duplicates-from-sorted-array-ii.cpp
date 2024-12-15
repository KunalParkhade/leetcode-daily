class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> count;
        int k = 0;

        for(int num:nums){
            count[num]++;
            if(count[num]<=2){
                nums[k] = num;
                k++;
            }
        }
        return k;
    }
};