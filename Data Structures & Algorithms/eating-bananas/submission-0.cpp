class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while (l <= r) {
            int m = (l + r) / 2;

            long long totaltime = 0;
            for (int p : piles) {
                totaltime += ceil(static_cast<double>(p) / m);
            }

            if (totaltime <= h) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }   

        return ans;
    }
};
