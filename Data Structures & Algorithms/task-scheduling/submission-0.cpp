class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> freq;
        for (auto x: tasks) {
            freq[x - 'A']++;
        }

        priority_queue<int> pq;

        int ans = 0, cycle;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) pq.push(freq[i]);
        }

        while (!pq.empty()) {
            cycle = n + 1;
            vector<int> store;
            int task_cnt = 0;

            while (cycle-- && !pq.empty()) {
                if (pq.top() > 1) {
                    store.push_back(pq.top() - 1);
                }
                pq.pop();
                task_cnt++;
            }

            for (auto x: store) pq.push(x);

            ans += pq.empty() ? task_cnt : n + 1;
        }

        return ans;
    }
};
