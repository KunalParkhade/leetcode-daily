class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int n=height.size();
        int ans=0;

        int i=0;
        while(i<n){
            while(!s.empty() && height[i]>height[s.top()]){
                int top=s.top();
                s.pop();
                if(s.empty())
                    break;
                int distance=i-s.top()-1;
                int bounded_h=min(height[i],height[s.top()])-height[top];
                ans+=distance*bounded_h;
            }
            s.push(i++);
        }
        return ans;
    }
};