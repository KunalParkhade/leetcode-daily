class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int a:arr){
            mp[a]++;
        }
        vector<int> freq;
        for(auto it:mp){
            freq.push_back(it.second);
        }

        sort(freq.begin(),freq.end());

        int elem_rem=0;
        for(int i=0;i<freq.size();i++){
            elem_rem+=freq[i];

            if(elem_rem>k){
                return freq.size()-i;
            }
        }

        return 0;
    }
};