class Solution {
public:
    void Helper(vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans,
                unordered_map<int, bool> mp) {
        if (ds.size() == arr.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (!mp[i]) {
                ds.push_back(arr[i]);
                mp[i] = 1;
                Helper(arr, ds, ans, mp);
                mp[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        unordered_map<int, bool> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[i] = 0;
        }

        Helper(nums, ds, ans, mp);

        return ans;
    }
};