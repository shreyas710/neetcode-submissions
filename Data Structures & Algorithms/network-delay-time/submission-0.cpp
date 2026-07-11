class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto x: times) {
            adj[x[0]].push_back({x[1], x[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({dist[k], k});

        while (!pq.empty()) {
            auto [dis, x] = pq.top();
            pq.pop();

            for (auto y: adj[x]) {
                int new_dist = dist[x] + y.second;
                if (new_dist < dist[y.first]) {
                    dist[y.first] = new_dist;
                    pq.push({dist[y.first], y.first});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
