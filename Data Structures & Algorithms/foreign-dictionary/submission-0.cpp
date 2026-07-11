class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        for (string w: words) {
            for (char c: w) {
                adj[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string a = words[i], b = words[i + 1];
            int min_len = min(a.length(), b.length());

            int j = 0;
            for (j = 0; j < min_len; j++) {
                if (a[j] != b[j]) {
                    if (!adj[a[j]].count(b[j])) {
                        adj[a[j]].insert(b[j]);
                        indegree[b[j]]++;
                    }
                    break;
                }
            }

            if (j == min_len && a.size() > b.size()) return "";
        }

        queue<char> q;
        for (auto [c, deg]: indegree) {
            if (deg == 0) q.push(c);
        }

        string ans;

        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            ans += x;
            for (auto y: adj[x]) {
                if (--indegree[y] == 0) {
                    q.push(y);
                }
            }
        }

        return ans.size() == indegree.size() ? ans : "";
    }
};
