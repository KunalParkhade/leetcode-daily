class Solution {
public:
    string makeGood(string s) {
        if(s.empty()){
            return "";
        }
        stack<char> st;
        for(char ch:s){
            if(!st.empty()&& abs(st.top()-ch)==32){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        string result;
        while(!st.empty()){
            result=st.top()+result;
            st.pop();
        }

        return result;
    }
};