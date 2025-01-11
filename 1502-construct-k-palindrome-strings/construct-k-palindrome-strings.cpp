class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() == k)
            return true;
        if (s.size() < k)
            return false;

        vector<int> freq(26);
        int oddfreq = 0;

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                oddfreq++;
            }
        }

        if (oddfreq <= k)
            return true;

        return false;
    }
};