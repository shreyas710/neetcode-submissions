class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        function<bool(int, int, int)> dfs = [&](int i, int j, int idx) -> bool {
            if (idx == word.size()) return true;
            
            char tmp = board[i][j];
            board[i][j] = '#';

            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && word[idx] == board[ni][nj]) {
                    if (dfs(ni, nj, idx + 1))
                        return true;
                }
            }

            board[i][j] = tmp;
            return false;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (word[0] == board[i][j]) {
                    if (dfs(i, j, 1))
                        return true;
                }
            }
        }

        return false;
    }
};
