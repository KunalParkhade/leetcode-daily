class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int left = 0, right = numbers.size() - 1;
        while(left<=right){
            if(target==numbers[left]+numbers[right]){
                ans[0]=left+1;
                ans[1]=right+1;
                break;
            }
            else if(target < numbers[left]+numbers[right]){
                right--;
            }
            else{
                left++; 
            }
        }
        return ans;
    }
};