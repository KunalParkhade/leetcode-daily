class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> dup;
        
        for(int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1; // Map to index (0-based)
            if(nums[index] < 0) { // If already marked negative, it's a duplicate
                dup.push_back(index + 1); // Push the duplicate
            } else {
                nums[index] = -nums[index]; // Mark as visited by negating
            }
        }

        return dup;
    }
};
