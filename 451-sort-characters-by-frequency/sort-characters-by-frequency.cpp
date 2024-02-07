class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        // Step 1: Count the frequency of each character
        for (char c : s) {
            mp[c]++;
        }

        // Step 2: Custom comparator function for sorting
        auto comp = [&](char a, char b) {
            if (mp[a] == mp[b]) {
                return a < b; // If frequencies are equal, sort based on character value
            }
            return mp[a] > mp[b]; // Sort based on frequency in decreasing order
        };

        // Step 3: Sort characters based on their frequency
        sort(s.begin(), s.end(), comp);

        // Step 4: Construct sorted string
        return s;
    }
};
