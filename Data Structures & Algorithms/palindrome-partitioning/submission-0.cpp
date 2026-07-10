class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;

        function <bool(int, int)> is_pal = [&](int l, int r) -> bool {
            while (l <= r) {
                if (s[l] != s[r]) return false;
                l++;
                r--;
            }

            return true;
        };

        function<void(int)> solve = [&](int idx) -> void {
            if (idx == s.length()) {
                ans.push_back(curr);
                return;
            }

            for (int i = idx; i < s.length(); ++i) {
                if (!is_pal(idx, i)) continue;
                curr.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1);
                curr.pop_back();
            }
        };


        solve(0);

        return ans;
    }
};
