class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==1){
            return 1;
        }
        unordered_map<char, int> freq;
        for(char c:s){
            freq[c]++;
        }
        int res=0;
        bool hasOddFrequency=false;

        for(auto& entry:freq){
            int freq=entry.second;
            //Check frequency is even
            if(freq%2==0){
                res+=freq;
            }
            else{
                res+=freq-1;
                hasOddFrequency=true;
            }
        }
        if(hasOddFrequency) return res+1;

        return res;
    }
};