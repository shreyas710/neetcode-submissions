class Solution {
public:
    bool checkPal(string s, int l, int r) {
        while (l < r && !isalnum(s[l])) l++;
        while (l < r && !isalnum(s[r])) r--;
        if (l >= r) return true;
        if (tolower(s[l]) != tolower(s[r])) return false;
        return checkPal(s, l + 1, r - 1);
    }

    bool isPalindrome(string s) {
        return checkPal(s, 0, s.size() - 1);
    }
};
