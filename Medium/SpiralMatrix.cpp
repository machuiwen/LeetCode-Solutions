class Solution {
public:
    // My solution. The steps are n -> m - 1 -> n - 1 -> m - 2 ->
    // n - 2 -> m - 3 -> ...
    // SEE THE CLEANED UP VERSION BELOW
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return vector<int>();
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = -1; 
        vector<int> result;
        while (true) {
            if (n == 0) break;
            for (int c = 0; c < n; c++) {
                j++;
                result.push_back(matrix[i][j]);
            }
            if (m - 1 <= 0) break;
            for (int c = 0; c < m - 1; c++) {
                i++;
                result.push_back(matrix[i][j]);
            }
            if (n - 1 <= 0) break;
            for (int c = 0; c < n - 1; c++) {
                j--;
                result.push_back(matrix[i][j]);
            }
            if (m - 2 <= 0) break;
            for (int c = 0; c < m - 2; c++) {
                i--;
                result.push_back(matrix[i][j]);
            }
            n -= 2;
            m -= 2;
        }
        return result;
    }
};

//-----------------Clean Up------------------------
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0) return result;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = -1; // row and col
        while (true) {
            for (int c = 0; c < n; c++) {
                result.push_back(matrix[i][++j]);
            }
            if (--m == 0) break;
            for (int c = 0; c < m; c++) {
                result.push_back(matrix[++i][j]);
            }
            if (--n == 0) break;
            for (int c = 0; c < n; c++) {
                result.push_back(matrix[i][--j]);
            }
            if (--m == 0) break;
            for (int c = 0; c < m; c++) {
                result.push_back(matrix[--i][j]);
            }
            if (--n == 0) break;
        }
        return result;
    }
};