class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> table(amount + 1, INT_MAX - 1);
        table[0] = 0;
        int n = coins.size();
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (coins[j] <= i) {
                    table[i] = min(table[i], 1 + table[i - coins[j]]);
                }
            }
        }
        if (table[amount] == INT_MAX - 1) return -1;
        return table[amount];
    }
};