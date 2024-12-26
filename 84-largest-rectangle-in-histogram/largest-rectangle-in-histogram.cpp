class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;

        stack<int> s;
        vector<int> prevSmaller(n), nextSmaller(n);

        // Finding the nearest smaller element on the left
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            prevSmaller[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) {
            s.pop();
        }

        // finding the nearest smaller element on the right
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            nextSmaller[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Calculating max area
        for (int i = 0; i < n; i++) {
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            int area = width * heights[i];
            res = max(res, area);
        }

        return res;
    }
};