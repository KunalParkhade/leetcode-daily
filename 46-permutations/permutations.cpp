class Solution {
public:
    void Helper(vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans,
                vector<bool>& used) {
        if (ds.size() == arr.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (!used[i]) {
                ds.push_back(arr[i]);
                used[i] = true;
                Helper(arr, ds, ans, used);
                used[i] = false;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> used(nums.size(), false);

        Helper(nums, ds, ans, used);

        return ans;
    }
};