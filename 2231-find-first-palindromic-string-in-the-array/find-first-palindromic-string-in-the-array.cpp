class Solution {
public:
    bool isPalindrome(string& s){
        int left=0;
        int right=s.size()-1;

        while(left<=right){
            if(s[left]!=s[right]){
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for (string s : words) {
            if(isPalindrome(s)){
                return s;
            }
        }
        return "";
    }
};