class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mps, mpt;
        int have = 0, ans = INT_MAX, l = 0;
        for (auto x: t) mpt[x]++;

        int need = mpt.size();
        pair<int, int> res = {-1, -1};

        for (int r = 0; r < s.length(); ++r) {
            mps[s[r]]++;
            if (mps[s[r]] == mpt[s[r]]) have++;

            while (have == need) {
                if ((r - l + 1) < ans) {
                    ans = r - l + 1;
                    res = {l, r};
                }
                mps[s[l]]--;
                if (mps[s[l]] < mpt[s[l]]) have--;
                l++;
            }
        }

        return ans == INT_MAX ? "" : s.substr(res.first, ans);
    }
};
