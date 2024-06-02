class Solution {
public:
    void reverseString(vector<char>& s) {
        reverseHelper(s,0,s.size()-1);
    }
    
private:
    void reverseHelper(vector<char>&s, int left, int right){
        if(left>=right){
            return;        //Base Case
        }
        
        swap(s[left],s[right]);
        
        //Recursive call on the remaining substring
        reverseHelper(s,left+1,right-1);
    }
};