class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n + 1, 1);
        string s;
        for (int i = 1; i <= n; i++) {
            fact[i] = i * fact[i - 1];
            s += i + '0';
        }
        string res;
        int order = n;
        k -= 1;
        while (order > 0) {
            int div = k / fact[order - 1];
            k %= fact[order - 1];
            res += s[div];
            s.erase(s.begin() + div);
            order--;
        }
        return res;
    }
};