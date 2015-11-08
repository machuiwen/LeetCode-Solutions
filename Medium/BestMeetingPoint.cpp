class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> x(grid[0].size());
        vector<int> y(grid.size());
        int sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                x[j] += grid[i][j];
                y[i] += grid[i][j];
                sum += grid[i][j];
            }
        }
        if (sum == 0) return 0;
        vector<int> x2 = x;
        vector<int> y2 = y;
        for (int i = 1; i < x.size(); i++) {
            x[i] = x[i] + x[i - 1];
        }
        for (int j = 1; j < y.size(); j++) {
            y[j] = y[j] + y[j - 1];
        }
        int xFinal = 0;
        while (sum - x[xFinal] > x[xFinal]) {
            xFinal++;
        }
        int yFinal = 0;
        while (sum - y[yFinal] > y[yFinal]) {
            yFinal++;
        }
        int mDist = 0;
        for (int i = 0; i < x.size(); i++) {
            mDist += x2[i] * abs(i - xFinal);
        }
        for (int i = 0; i < y.size(); i++) {
            mDist += y2[i] * abs(i - yFinal);
        }
        return mDist;
    }
};