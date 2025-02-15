class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // vector<int> ans(2);
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (target == numbers[left] + numbers[right]) {
                return {left + 1, right + 1};
            } else if (target < numbers[left] + numbers[right]) {
                right--;
            } else {
                left++;
            }
        }
        return {-1, -1};
    }
};