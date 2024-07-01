class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int countOne=0;
        int max=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                countOne++;
            }
            if(max<countOne){
                max=countOne;
            }

            if(nums[i]==0){
                countOne=0;
            }
        }

        return max;
    }
};