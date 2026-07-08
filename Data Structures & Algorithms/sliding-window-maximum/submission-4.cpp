class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(int N, vector<int>& A) {
        this->n = N;
        while (__builtin_popcount(n) != 1) {
            n++;
        }
        build(N, A);
    }

    void build(int N, vector<int>& A) {
        tree.resize(2 * n, INT_MIN);
        for (int i = 0; i < N; ++i) {
            tree[n + i] = A[i];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    int query(int l, int r) {
        int ans = INT_MIN;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = max(ans, tree[l++]);
            if (r & 1) ans = max(ans, tree[--r]);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree st(n, nums);
        vector<int> ans;
        for (int i = 0; i <= n - k; ++i) {
            ans.push_back(st.query(i, i + k - 1));
        }
        return ans;
    }
};
