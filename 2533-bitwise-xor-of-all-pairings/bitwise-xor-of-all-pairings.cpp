class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        int xor1 = 0, xor2 = 0;

        for (int num : nums1) xor1 ^= num;
        for (int num : nums2) xor2 ^= num;

        int ans = 0;
        if (m % 2 == 1) ans ^= xor1; // nums1 contributes when nums2 size is odd
        if (n % 2 == 1) ans ^= xor2; // nums2 contributes when nums1 size is odd

        return ans;
    }
};
