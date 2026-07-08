class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, maxx = 0, ans = 0;

        for (r = 0; r < s.length(); ++r) {
            mp[s[r]]++;
            maxx = max(maxx, mp[s[r]]);

            while (r - l + 1 - maxx > k) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
