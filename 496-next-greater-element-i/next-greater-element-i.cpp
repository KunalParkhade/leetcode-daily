class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> hash;
        hash[nums2[nums2.size()-1]]=-1;
        s.push(nums2[nums2.size()-1]);

        for(int i=nums2.size()-2;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            int res=s.empty()?-1:s.top();
            hash[nums2[i]]=res;
            s.push(nums2[i]);
        }

        vector<int> result;
        for(int i=0;i<nums1.size();i++){
            result.push_back(hash[nums1[i]]);
        }

        return result;
    }
};