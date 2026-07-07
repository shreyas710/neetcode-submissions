class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], maxx = 0;

        for (int i = 1; i < prices.size(); ++i) {
            buy = min(buy, prices[i]);
            maxx = max(maxx, prices[i] - buy);
        }

        return maxx;
    }
};
