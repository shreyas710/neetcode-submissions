class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxarea = 0;

        for (int i = 0; i < n; i++) {
            int ht = heights[i];

            int r = i + 1;
            while (r < n && heights[r] >= ht)
                r++;

            int l = i;
            while (l >= 0 && heights[l] >= ht)
                l--;

            r--;
            l++;
            maxarea = max(maxarea, ht * (r - l + 1));
        }

        return maxarea;
    }
};
