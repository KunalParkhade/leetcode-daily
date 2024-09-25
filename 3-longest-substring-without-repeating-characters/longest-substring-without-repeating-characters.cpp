class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, maxlen=0;
        int n = s.length();
        vector<int> hash(255, -1);

        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l = hash[s[r]] + 1;
                }
            }
            maxlen = max(maxlen, r-l+1);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};