class Solution {
public:
    int pivotInteger(int n) {
        for(int i=1;i<=n;i++){
            int sumleft=0,sumright=0;

            for(int j=1;j<=i;j++){
                sumleft+=j;
            }
            for(int k=i;k<=n;k++){
                sumright+=k;
            }

            if(sumleft==sumright){
                return i;
            }
        }


        return -1;
    }
};