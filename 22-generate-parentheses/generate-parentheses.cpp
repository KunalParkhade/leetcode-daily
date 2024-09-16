class Solution {
public:
    void Helper(int n, int open, int close, string s, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(s);
            return;
        }

        if (open < n) {
            Helper(n, open + 1, close, s + '(', result);
        }

        if (close < open) {
            Helper(n, open, close + 1, s + ')', result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        Helper(n, 0, 0, s, result);
        return result;
    }
};