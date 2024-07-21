class Solution {
public:
    void findCombinationHelper(int ind, vector<int>& arr, int target,
                               vector<int>& ds, vector<vector<int>>& ans) {
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = ind; i<arr.size();i++){
            if(arr[i]>target)   break;
            ds.push_back(arr[i]);
            findCombinationHelper(i, arr, target-arr[i], ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> ans;
        vector<int> ds;

        sort(candidates.begin(), candidates.end());
        // Sorting se  -> agar bada element mila remaining target se to break kr dena

        findCombinationHelper(0, candidates, target, ds, ans);

        return ans;
    }
};