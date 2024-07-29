class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int len;
        int left = 0, right = 0, zeroes = 0;
        while (right < n) {
            if (nums[right] == 0)
                zeroes++;
            while (zeroes > k) {
                if (nums[left] == 0)
                    zeroes--;
                left++;
            }
            if (zeroes <= k) {
                len = right - left + 1;
                maxLen = max(maxLen, len);
            }
            right++;
        }
        return maxLen;
    }
};