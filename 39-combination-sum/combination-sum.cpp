class Solution {
public:
    void findCombinationHelper(int ind, vector<int>& arr, int target,
                               vector<int>& ds, vector<vector<int>>& ans) {
        if (ind == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if (arr[ind] <= target) {
            // Condition for Pick up the element
            ds.push_back(arr[ind]);
            findCombinationHelper(ind, arr, target - arr[ind], ds, ans);
            ds.pop_back();
        }

        // Not Pick
        findCombinationHelper(ind + 1, arr, target, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> ans;
        vector<int> ds;

        findCombinationHelper(0, candidates, target, ds, ans);

        return ans;
    }
};