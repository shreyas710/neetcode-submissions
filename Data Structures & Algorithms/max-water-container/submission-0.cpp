class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int maxx = 0;

        while (l < r) {
            maxx = max(maxx, min(heights[l], heights[r]) * (r - l));
            if (heights[l] < heights[r]) l++;
            else r--;
        }

        return maxx;
    }
};
