class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int conOdds=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2!=0){
                conOdds++;
            }
            else{
                conOdds=0;
            }

            if(conOdds==3){
                return true;
            }
        }

        return false;
    }
};