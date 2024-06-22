class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n==0)    //edge case
            return false;
        
        for(int i=0;i<=30;i++){
            if(n==pow(2,i)){
                return true;
            }
        }
        return false;
    }
};