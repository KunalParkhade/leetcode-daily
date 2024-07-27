class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        vector<int> hash(255, -1);
        int left = 0, right = 0;

        while (right < n) {
            if (hash[s[right]] != -1 && hash[s[right]] >= left) {
                left = max(left, hash[s[right]] + 1);
            }
            hash[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};