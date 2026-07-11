class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) return false;

        vector<vector<int>> adj(n);
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> vis;
        queue<pair<int, int>> q;

        q.push({0, -1});
        vis.insert(0);

        while (!q.empty()) {
            auto [node, par] = q.front();
            q.pop();

            for (auto x: adj[node]) {
                if (x == par) continue;
                if (vis.count(x)) return false;
                vis.insert(x);
                q.push({x, node});
            }
        }

        return vis.size() == n;
    }
};
