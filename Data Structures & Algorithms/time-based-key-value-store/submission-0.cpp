class TimeMap {
    map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& vals = mp[key];

        int l = 0, r = vals.size() - 1;
        string ans = "";

        while (l <= r) {
            int m = (l + r) / 2;
            if (timestamp >= vals[m].first) {
                ans = vals[m].second;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }
};
