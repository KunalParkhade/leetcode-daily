class Solution {
public:
    int trap(vector<int>& height) {
        // int i = 0, left_max = height[0], sum = 0;
        // int j = height.size() - 1, right_max = height[j];
        // while (i < j) {
        //     if (left_max <= right_max) {
        //         sum += (left_max - height[i]);
        //         i++;
        //         left_max = max(left_max, height[i]);
        //     } else {
        //         sum += (right_max - height[j]);
        //         j--;
        //         right_max = max(right_max, height[j]);
        //     }
        // }
        // return sum;
        int n = height.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }
        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        int total = 0;

        for (int i = 0; i < n; i++) {
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];
            if (leftMax > height[i] && rightMax > height[i]) {
                total += min(leftMax, rightMax) - height[i];
            }
        }
        return total;
    }
};