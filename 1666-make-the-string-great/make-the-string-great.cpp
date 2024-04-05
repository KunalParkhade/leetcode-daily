class Solution {
public:
    string makeGood(string s) {
        if (s.empty()) {
            return "";
        }
        stack<char> st;
        for (char ch : s) {
            if (!st.empty() && abs(st.top() - ch) == 32) {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        stringstream ss;
        while (!st.empty()) {
            ss << st.top();
            st.pop();
        }
        string result=ss.str();
        reverse(result.begin(),result.end());

        return result;
    }
};
