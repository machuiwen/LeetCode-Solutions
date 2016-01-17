class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<int> table(n, 1); // index = number
        table[0] = 0;
        table[1] = 0;
        for (int i = 2; i <= sqrt(n); i++) {
            if (table[i] == 1) {
                int factor = 2;
                while (i * factor < n) {
                    table[i * factor] = 0;
                    factor++;
                }
            }
        }
        return accumulate(table.begin(), table.end(), 0);
    }
};