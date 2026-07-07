class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for (auto x: nums) {
            if (s.count(x - 1) == 0) {
                int curr = x, tmp = 0;
                while (s.count(curr)) {
                    tmp++;
                    curr++;
                }
                ans = max(ans, tmp);
            }
        }

        return ans;
    }
};
