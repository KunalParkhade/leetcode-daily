class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> netShifts(n + 1, 0); 

        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = (shift[2] == 1) ? 1 : -1;

            netShifts[start] += direction;
            netShifts[end + 1] -= direction;
        }

        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeShift += netShifts[i];
            int shiftValue = ((s[i] - 'a') + cumulativeShift) % 26;
            if (shiftValue < 0) shiftValue += 26; // Handle negative shifts
            s[i] = 'a' + shiftValue;
        }

        return s;
    }
};
