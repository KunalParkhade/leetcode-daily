class Solution {
public:
    void combinationHelper(int ind, int target, vector<int>& ds, vector<vector<int>>& ans, vector<int>& arr){
        if(target == 0){
            ans.push_back(ds);
        }

        for(int i = ind; i < arr.size(); i++){
            if(i > ind && arr[i] == arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            combinationHelper(i+1, target-arr[i], ds, ans, arr);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;

        combinationHelper(0, target, ds, ans, candidates);

        return ans;
    }
};