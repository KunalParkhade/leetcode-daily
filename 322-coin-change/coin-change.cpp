class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int amt=1;amt<=amount;amt++){
            for(auto i:coins){
                if(amt-i>=0){
                    dp[amt]=min(dp[amt],1+dp[amt -i]);
                }
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
    }
};