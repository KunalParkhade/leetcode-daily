class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int result = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (result != 0) {
                    break;
                }
            } else {
                result++;
            }
        }
        return result;
    }
};