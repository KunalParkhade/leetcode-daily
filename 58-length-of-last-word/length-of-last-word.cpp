class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool foundWord = false;
        
        // Traverse the string from right to left
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                foundWord = true; // Mark that we have found a non-space character
                length++; // Increment the length of the word
            } else if (foundWord) {
                // If we encounter a space after finding a word, then we have found the last word
                break;
            }
        }
        
        return length;
    }
};