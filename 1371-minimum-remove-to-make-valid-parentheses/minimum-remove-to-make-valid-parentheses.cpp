class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int lcount=0,rcount=0;
        stack<char> st;

        for(char ch:s){
            if(ch=='('){
                lcount++;
            }
            else if(ch==')'){
                rcount++;
            }
            if(rcount>lcount){
                rcount--;
                continue;
            }else{
                st.push(ch);
            }
        }

        string result="";
        while(!st.empty()){
            char currChar=st.top();
            st.pop();
            if(lcount>rcount && currChar=='('){
                lcount--;
            } else{
                result+=currChar;
            }
        }

        reverse(result.begin(),result.end());

        return result;
    }
};