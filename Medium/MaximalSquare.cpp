class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        vector<vector<int>> table(m, vector<int>(n, 0));
        int maxEdgeLen = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != '0') {
                    if (i == 0 || j == 0) {
                        table[i][j] = 1;
                    } else {
                        table[i][j] = 1 + min(table[i - 1][j - 1], min(table[i - 1][j], table[i][j - 1]));
                    }
                }
                maxEdgeLen = max(maxEdgeLen, table[i][j]);
            }
        }
        return maxEdgeLen * maxEdgeLen;
    }
};