class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        summat = matrix;
        m = matrix.size();
        if (m == 0) return;
        n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    summat[0][j] += summat[0][j - 1];
                } else if (j == 0) {
                    summat[i][0] += summat[i - 1][0];
                } else {
                    summat[i][j] += summat[i - 1][j] + summat[i][j - 1] - summat[i - 1][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = summat[row2][col2];
        if (row1 > 0) res -= summat[row1 - 1][col2];
        if (col1 > 0) res -= summat[row2][col1 - 1];
        if (row1 > 0 && col1 > 0) res += summat[row1 - 1][col1 - 1];
        return res;
    }
private:
    vector<vector<int>> summat;
    int m, n;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);