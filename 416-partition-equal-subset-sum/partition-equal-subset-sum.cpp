class Solution {
public:
    bool Helper(int ind, int target, vector<int>& arr,
                vector<vector<int>>& dp) {
        if (target == 0)
            return true;
            
        if (ind == 0)
            return (arr[0] == target);
        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notTake = Helper(ind - 1, target, arr, dp);
        bool take = false;
        if (target >= arr[ind])
            take = Helper(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0)
            return false;

        int totSum = sum / 2;

        vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));

        // return Helper(n - 1, nums, sum/2);
        return Helper(n-1, totSum, nums, dp);
    }
};