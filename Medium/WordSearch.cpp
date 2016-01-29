class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        int n = board.size();
        if (n == 0) return false;
        int m = board[0].size();
        if (m == 0) return false;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, visited, i, j, word.substr(1))) return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string word) {
        if (word.empty()) return true;
        visited[i][j] = true;
        if (i > 0 && !visited[i - 1][j] && board[i - 1][j] == word[0] && dfs(board, visited, i - 1, j, word.substr(1))) {
            return true;
        }
        if (i < board.size() - 1 && !visited[i + 1][j] && board[i + 1][j] == word[0] && dfs(board, visited, i + 1, j, word.substr(1))) {
            return true;
        }
        if (j > 0 && !visited[i][j - 1] && board[i][j - 1] == word[0] && dfs(board, visited, i, j - 1, word.substr(1))) {
            return true;
        }
        if (j < board[0].size() - 1 && !visited[i][j + 1] && board[i][j + 1] == word[0] && dfs(board, visited, i, j + 1, word.substr(1))) {
            return true;
        }
        visited[i][j] = false;
        return false;
    }
};