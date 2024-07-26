class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }
        int maxFreq = 0;
        int mostFreqEven = -1;
        for(const auto& [num, count] : freq) {
            if(num % 2 == 0) {
                if(count > maxFreq || (count == maxFreq && num < mostFreqEven)) {
                    maxFreq = count;
                    mostFreqEven = num;
                }
            }
        }
        return mostFreqEven;
    }
};
