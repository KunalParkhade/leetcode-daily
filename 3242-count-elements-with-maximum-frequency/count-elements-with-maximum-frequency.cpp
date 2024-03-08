class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxfreq = 0;
        int max_freq_elem = 0;
        
        for (int num : nums) {
            mp[num]++;
            if (mp[num] > maxfreq) {
                maxfreq = mp[num];
                max_freq_elem = 1; // Reset count of max frequency element
            } else if (mp[num] == maxfreq) {
                max_freq_elem++;
            }
        }
        
        return maxfreq * max_freq_elem;
    }
};