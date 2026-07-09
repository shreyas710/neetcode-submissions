class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;

        function<void(int, vector<int>&)> solve = [&](int idx, vector<int>& nums) -> void {
            ans.push_back(tmp);
            for (int i = idx; i < nums.size(); ++i) {
                tmp.push_back(nums[i]);
                solve(i + 1, nums);
                tmp.pop_back();
            }
        };

        solve(0, nums);
        return ans;
    }
};
