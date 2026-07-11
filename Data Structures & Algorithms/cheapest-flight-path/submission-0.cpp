class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto f: flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        int stops = 0;
        vector<int> dist(n + 1, INT_MAX);
        dist[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});

        while (stops <= k && !q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, d] = q.front();
                q.pop();
                for (auto y: adj[x]) {
                    int new_d = d + y.second;
                    if (dist[y.first] > new_d) {
                        dist[y.first] = new_d;
                        q.push({y.first, new_d});
                    }
                }
            }
            stops++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
