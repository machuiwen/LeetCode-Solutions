class Solution {
public:
    int uniquePaths(int m, int n) {
        int paths[m][n];
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 || col == 0) {
                    paths[row][col] = 1;
                } else {
                    paths[row][col] = paths[row - 1][col] + paths[row][col - 1];
                }
            }
        }
        return paths[m - 1][n - 1];
    }
};