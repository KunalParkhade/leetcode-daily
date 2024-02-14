class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int posIndex = 0, negIndex = 1;
        
        // Arrange positive integers first
        for (int num : nums) {
            if (num > 0) {
                result[posIndex] = num;
                posIndex += 2;
            }
        }
        
        // Arrange negative integers next
        for (int num : nums) {
            if (num < 0) {
                result[negIndex] = num;
                negIndex += 2;
            }
        }
        
        return result;
    }
};