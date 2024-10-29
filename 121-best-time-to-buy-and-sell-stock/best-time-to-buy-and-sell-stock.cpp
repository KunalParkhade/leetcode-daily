class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = prices[0];
        int profit = 0, maxProfit = 0;

        for (int i = 0; i < n; i++) {
            if (minPrice > prices[i]) {
                minPrice = prices[i];
            } else {
                profit = prices[i] - minPrice;
            }
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};