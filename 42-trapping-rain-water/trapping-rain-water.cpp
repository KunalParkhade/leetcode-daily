class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lMax = 0, rMax = 0, total = 0, left = 0, right = n - 1;

        while (left < right) {
            if (height[left] <= height[right]) {
                if (lMax > height[left]) {
                    total += lMax - height[left];
                } else {
                    lMax = height[left];
                }
                left++;
            } else {
                if (rMax > height[right]) {
                    total += rMax - height[right];
                } else {
                    rMax = height[right];
                }
                right--;
            }
        }
        return total;
    }
};