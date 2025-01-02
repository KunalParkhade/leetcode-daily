class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

        vector<int> prefixSum(words.size());
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            string currWord = words[i];
            if (vowels.count(currWord[0]) &&
                vowels.count(currWord[currWord.size() - 1])) {
                count++;
            }
            prefixSum[i] = count;
        }

        //Process Queries
        for(const auto& currQuery:queries){
            int left = currQuery[0];
            int right = currQuery[1];
            int result =prefixSum[right] - (left==0?0:prefixSum[left-1]);
            ans.push_back(result);
        }

        return ans;
    }
};