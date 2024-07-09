class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int prefixSum=0;
        double wT = 0;

        for(int i=0;i<n;i++){
            int a = customers[i][0];
            int b = customers[i][1];

            if(prefixSum < a){
                prefixSum = a;
            }
            
            prefixSum += b;
            wT += prefixSum - a;
        }

        return wT/n;
    }
};