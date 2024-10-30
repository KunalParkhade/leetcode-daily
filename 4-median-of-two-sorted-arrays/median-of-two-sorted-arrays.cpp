class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> fin;

        for(auto num:nums1)
            fin.push_back(num);
        
        for(auto num:nums2)
            fin.push_back(num);

        sort(fin.begin(), fin.end());

        int n = fin.size();

        return n%2?fin[n/2]:(fin[n/2-1]+fin[n/2])/2.0;
    }
};