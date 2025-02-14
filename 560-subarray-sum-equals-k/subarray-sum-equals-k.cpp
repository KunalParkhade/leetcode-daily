class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, sum = 0;
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // Initialize to handle cases where sum == k directly

        for (int i = 0; i < n; i++) {
            sum += nums[i];
//             For each element, it checks if there exists a previous prefix sum such that when     subtracted from the current cumulative sum (sum), it equals 
// k
// k. This is done by checking if sum - k exists in prefixSumCount.
            // Check if there exists a prefix sum that makes the subarray sum to k
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }

            // Increment the count of the current prefix sum
            prefixSumCount[sum]++;
        }
        return count;
    }
};
