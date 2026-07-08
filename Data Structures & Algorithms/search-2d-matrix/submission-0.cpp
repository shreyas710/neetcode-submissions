class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int l = 0, r = n * m - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            int row = mid / m, col = mid % m;
            if (target > matrix[row][col]) l = mid + 1;
            else if (target < matrix[row][col]) r = mid - 1;
            else return true;
        }

        return false;
    }
};
