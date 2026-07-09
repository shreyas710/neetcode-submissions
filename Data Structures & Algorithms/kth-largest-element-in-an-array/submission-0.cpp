class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        function<int(vector<int>&, int)> quick_select = [&](vector<int>& nums, int k) -> int {
            int n = nums.size();
            int pivot = nums[rand() % n];

            vector<int> l, r, m;

            for (auto x: nums) {
                if (x < pivot) l.push_back(x);
                else if (x > pivot) r.push_back(x);
                else m.push_back(x);
            }

            if (k <= l.size()) return quick_select(l, k);
            else if (k > l.size() + m.size()) return quick_select(r, k - l.size() - m .size());
            return pivot;
        };

        return quick_select(nums, nums.size() - k + 1);
    }
};
