class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer;
        for(int a:nums){
            answer.push_back(a*a);
        }
        sort(answer.begin(),answer.end());
        return answer;
    }
};