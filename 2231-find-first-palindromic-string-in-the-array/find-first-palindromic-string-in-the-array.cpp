class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(int i=0;i<n;i++){
            string x = string(words[i].rbegin(),words[i].rend());
            if(x == words[i]){
                return words[i];
            }
        }
        return "";
    }
};