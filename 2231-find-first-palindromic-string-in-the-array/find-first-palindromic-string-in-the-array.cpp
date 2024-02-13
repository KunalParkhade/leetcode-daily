class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string s : words) {
            string origin = s;
            reverse(origin.begin(), origin.end());
            
            if (s == origin) {
                return s;
            }
        }
        return "";
    }
};