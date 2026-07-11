class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;

        for (auto ticket: tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        for (auto& [src, dest]: adj) {
            sort(dest.rbegin(), dest.rend());
        }

        vector<string> ans;
        stack<string> s;
        s.push("JFK");

        while (!s.empty()) {
            string curr = s.top();
            if (adj[curr].empty()) {
                ans.push_back(curr);
                s.pop();
            } else {
                string nxt = adj[curr].back();
                adj[curr].pop_back();
                s.push(nxt);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
