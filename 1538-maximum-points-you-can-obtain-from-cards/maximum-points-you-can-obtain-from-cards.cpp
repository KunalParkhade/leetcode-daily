class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0, rsum = 0, maxSum = 0;

        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        maxSum = lsum;

        // Sliding window to calculate the sum by including cards from the end
        for (int i = 0; i < k; i++) {
            lsum -= cardPoints[k - 1 - i];    
            rsum += cardPoints[n - 1 - i];    

            maxSum = max(maxSum, lsum + rsum); // Update maxSum if current window sum is greater
        }

        return maxSum;
    }
};
