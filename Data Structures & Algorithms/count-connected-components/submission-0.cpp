class DSU {
    public:
    vector<int> par, rank;

    DSU(int n) {
        par.resize(n);
        rank.resize(n, 1);

        for (int i = 0; i < n; i++) par[i] = i;
    }

    int dsu_find(int node) {
        if (node == par[node]) return node;
        return par[node] = dsu_find(par[node]);
    }

    bool dsu_union(int x, int y) {
        int px = dsu_find(x), py = dsu_find(y);
        if (px == py) return false;

        if (rank[py] > rank[px]) swap(px, py);

        par[py] = px;
        rank[px] += rank[py];
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int ans = n;
        for (auto edge: edges) {
            if (dsu.dsu_union(edge[0], edge[1]))
                ans--;
        }

        return ans;
    }
};
