class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftParentheses, asterisks;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                leftParentheses.push(i);
            } else if (s[i] == '*') {
                asterisks.push(i);
            } else { // Encountered a right parenthesis
                if (!leftParentheses.empty()) {
                    leftParentheses.pop();
                } else if (!asterisks.empty()) {
                    asterisks.pop();
                } else {
                    return false; // No matching left parenthesis or asterisk found
                }
            }
        }

        // Pair remaining left parentheses with asterisks
        while (!leftParentheses.empty() && !asterisks.empty()) {
            if (leftParentheses.top() < asterisks.top()) {
                leftParentheses.pop();
                asterisks.pop();
            } else {
                break;
            }
        }

        return leftParentheses.empty();
    }
};