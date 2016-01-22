class Solution {
public:
    int numSquares(int n) {
        vector<int> table(n + 1);
        table[1] = 1;
        for (int i = 2; i <= n; i++) {
            int minSum = i;
            for (int j = sqrt(i); j >= 1; j--) {
                minSum = min(table[i - (j * j)] + 1, minSum);
            }
            table[i] = minSum;
        }
        return table[n];
    }
};