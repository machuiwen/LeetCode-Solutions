class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> table = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    table[i][j] = j;
                } else if (j == 0) {
                    table[i][j] = i;
                } else {
                    int insertion = 1 + table[i][j - 1];
                    int deletion = 1 + table[i - 1][j];
                    int replace = table[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1);
                    table[i][j] = min(insertion, min(deletion, replace));
                }
            }
        }
        return table[m][n];
    }
};