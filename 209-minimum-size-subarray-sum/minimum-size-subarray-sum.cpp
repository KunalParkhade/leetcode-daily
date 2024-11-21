class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = 0, n = nums.size();
        int minLen = INT_MAX, sum = 0;
        // Brute force
        // for (int i = 0; i < n; i++) {
        //     sum = 0;
        //     for (int j = i; j < n; j++) {
        //         sum += nums[j];
        //         if (sum >= target) {
        //             len = j - i + 1;
        //             minLen = min(minLen, len);
        //         }
        //     }
        // }

        // return minLen != INT_MAX ? minLen : 0;

        // Sliding window
        int right = 0, left = 0;
        while (right < n) {
            sum += nums[right];
            while (sum >= target) {
                len = right - left + 1;
                minLen = min(minLen, len);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};