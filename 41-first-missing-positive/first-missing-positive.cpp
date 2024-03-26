class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        vector<bool> a(n+1);
        for(int num:nums){
            if(num>0 && num<=n){
                a[num]=true;
            }
        }
        for(int i=1;i<=n;i++){
            if(!a[i]){
                return i;
            }
        }

        return n+1;
    }
};