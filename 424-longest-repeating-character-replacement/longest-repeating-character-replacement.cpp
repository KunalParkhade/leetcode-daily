class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int right = 0, left = 0, maxlen = 0, maxf;
        int hash[26] = {0};

        while (right < n) {
            hash[s[right] - 'A']++;
            maxf = max(maxf, hash[s[right] - 'A']);

            int changes = right - left + 1 - maxf;
            if (changes > k) {
                hash[s[left] - 'A']--;
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
            right++;
        }
        return maxlen;
    }
};