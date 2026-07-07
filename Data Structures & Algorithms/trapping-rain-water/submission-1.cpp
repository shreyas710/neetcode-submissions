class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        stack<int> s;
        int ans = 0;

        for (int i = 0; i < height.size(); ++i) {
            while (!s.empty() && height[i] >= height[s.top()]) {
                int m = height[s.top()];
                s.pop();

                if (!s.empty()) {
                    int r = height[i], l = height[s.top()];
                    int h = min(l, r) - m;
                    int w = i - s.top() - 1;
                    ans += h * w;
                }
            }
            s.push(i);
        }

        return ans;
    }
};
