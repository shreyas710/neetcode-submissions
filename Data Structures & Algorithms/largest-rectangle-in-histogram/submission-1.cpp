class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> l(n, -1), r(n, n);

        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) 
                s.pop();
            if (!s.empty()) l[i] = s.top();
            s.push(i);
        } 

        while (!s.empty()) s.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            if (!s.empty()) r[i] = s.top();
            s.push(i);
        }

        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            l[i] += 1;
            r[i] -= 1;
            maxarea = max(maxarea, heights[i] * (r[i] - l[i] + 1));
        }

        return maxarea;
    }
};
