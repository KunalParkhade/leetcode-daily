class Solution {
public:
    void Helper(int n, int open, int close, string& s, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(s);
            return;
        }

        if (open < n) {
            s.push_back('(');
            Helper(n, open + 1, close, s, result);
            s.pop_back();
        }

        if (close < open) {
            s.push_back(')');
            Helper(n, open, close + 1, s, result);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        Helper(n, 0, 0, s, result);
        return result;
    }
};