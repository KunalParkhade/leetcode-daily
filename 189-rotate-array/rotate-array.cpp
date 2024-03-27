class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n=nums.size();
        k=k%n;
        
        if(k==0) return;

        reverse(nums.begin(),nums.end());//Reverse the entire vector
        reverse(nums.begin(),nums.begin()+k);//Reverse the first k elements
        reverse(nums.begin()+k,nums.end());//Reverse the remaining elements

    }
};