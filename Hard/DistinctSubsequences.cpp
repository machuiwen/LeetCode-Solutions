class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if (n < m) return 0;
        vector<vector<int>> table(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            table[i - 1][0] = 1; // base case
            int upper = min(i, m);
            for (int j = 1; j <= upper; j++) {
                if (s[i - 1] == t[j - 1]) {
                    table[i][j] = table[i - 1][j] + table[i - 1][j - 1];
                } else {
                    table[i][j] = table[i - 1][j];
                }
            }
        }
        return table[n][m];
    }
};