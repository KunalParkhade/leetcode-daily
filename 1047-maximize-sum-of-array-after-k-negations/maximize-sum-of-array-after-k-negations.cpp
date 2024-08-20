class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
        }

        if (k % 2 == 1) {
            int minElementIndex =
                min_element(nums.begin(), nums.end()) - nums.begin();
            nums[minElementIndex] = -nums[minElementIndex];
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        return sum;
    }
};