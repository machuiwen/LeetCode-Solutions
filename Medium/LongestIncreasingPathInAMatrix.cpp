class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> LIP(m, vector<int>(n, -1));
        int maxLen = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (LIP[i][j] == -1) {
                    dfs(matrix, i, j, LIP, maxLen);
                }
            }
        }
        return maxLen;
    }
    
    void dfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& LIP, int& maxLen) {
        int len = 1;
        int val = matrix[row][col];
        if (row > 0 && matrix[row - 1][col] > val) {
            if (LIP[row - 1][col] == -1) {
                dfs(matrix, row - 1, col, LIP, maxLen);
            }
            len = max(len, 1 + LIP[row - 1][col]);
        }
        if (row < matrix.size() - 1 && matrix[row + 1][col] > val) {
            if (LIP[row + 1][col] == -1) {
                dfs(matrix, row + 1, col, LIP, maxLen);
            }
            len = max(len, 1 + LIP[row + 1][col]);
        }
        if (col > 0 && matrix[row][col - 1] > val) {
            if (LIP[row][col - 1] == -1) {
                dfs(matrix, row, col - 1, LIP, maxLen);
            }
            len = max(len, 1 + LIP[row][col - 1]);
        }
        if (col < matrix[0].size() - 1 && matrix[row][col + 1] > val) {
            if (LIP[row][col + 1] == -1) {
                dfs(matrix, row, col + 1, LIP, maxLen);
            }
            len = max(len, 1 + LIP[row][col + 1]);
        }
        LIP[row][col] = len;
        maxLen = max(maxLen, len);
    }
};