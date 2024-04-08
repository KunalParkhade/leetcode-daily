class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        unordered_map<int,int> s;
        
        for(int a:students){
            q.push(a);
            s[a]++;
        }
        int i=0;
        
        while(!q.empty() && s[sandwiches[i]]>0){
            if(q.front()==sandwiches[i]){
                q.pop();
                s[sandwiches[i]]--;
                i++;
            }
            else{
                int a=q.front();
                q.pop();
                q.push(a);
            }
        }
        return q.size();
    }
};