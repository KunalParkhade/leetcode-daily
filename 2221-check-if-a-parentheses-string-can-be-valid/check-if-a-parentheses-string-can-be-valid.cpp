class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2==1) return false;

        stack<int> open, unlock;

        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                unlock.push(i);
            }
            else if(s[i]=='('){
                open.push(i);
            }
            else if(s[i]==')'){
                if(!open.empty()){
                    open.pop();
                }
                else if(!unlock.empty()){
                    unlock.pop();
                }
                else{
                    return false;
                }
            }
        }

        while(!open.empty() && !unlock.empty() && open.top() < unlock.top()){
            open.pop();
            unlock.pop();
        }

        if(!open.empty()){
            return false;
        }

        return true;
    }
};