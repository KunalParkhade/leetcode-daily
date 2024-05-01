class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> stack;
        string result;

        int index = 0;
        while (index < word.length()) {
            stack.push(word[index]);
            // Found ch
            if (word[index] == ch) {
                // Add characters through ch to the result in reverse order
                while (!stack.empty()) {
                    result.push_back(stack.top());
                    stack.pop();
                }
                index++;
                // Add the rest of the characters to result
                while (index < word.length()) {
                    result.push_back(word[index]);
                    index++;
                }
                return result;
            }
            index++;
        }

        return word;
    }
};