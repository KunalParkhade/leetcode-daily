class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left=0, right=0, maxlen=0;
        unordered_map<int, int> mp;
        while(right < n){
            mp[fruits[right]]++;
            // if(mp[fruits[right]]==0){
            //     mp.erase(fruits[right]);
            // }
            if(mp.size()>2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }else{
                maxlen = max(maxlen, right - left + 1);
            }
            right++;
        }
        return maxlen;
    }
};