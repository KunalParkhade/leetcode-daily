class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> maxfreq(26, 0);

        for(const string& word:words2){
            vector<int> freq(26, 0);
            for(char c:word){
                freq[c - 'a']++;
            }
            for(int i=0;i<26;i++){
                maxfreq[i] = max(maxfreq[i], freq[i]);
            }
        }

        //check for each word in words1
        for(const string& word: words1){
            vector<int> freq(26, 0);
            for(char c:word){
                freq[c - 'a']++;
            }

            bool isUniversal=true;

            for(int i=0;i<26;i++){
                if(freq[i]<maxfreq[i]){
                    isUniversal=false;
                    break;
                }
            }
            if(isUniversal){
                ans.push_back(word);
            }
        }

        return ans;
    }
};