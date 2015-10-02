class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int paths[m][n];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    paths[i][j] = 0;
                } else {
                    if (i == m - 1 && j == n - 1) {
                        paths[i][j] = 1;
                    } else if (i == m - 1) {
                        paths[i][j] = paths[i][j + 1];
                    } else if (j == n - 1) {
                        paths[i][j] = paths[i + 1][j];
                    } else {
                        paths[i][j] = paths[i + 1][j] + paths[i][j + 1];
                    }
                }
            }
        }
        return paths[0][0];
    }
};