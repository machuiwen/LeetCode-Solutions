class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> chosen;
        helper(n, result, chosen, -1);
        return result;
    }
    
    void helper(int n, vector<vector<int>>& result, vector<int>& chosen, int lower) {
        // n as one factor, also act as base case
        if (lower != -1) {
            chosen.push_back(n);
            result.push_back(chosen);
            chosen.pop_back();
        }
        // further divide n
        int upper = sqrt(n);
        for (int i = max(2, lower); i <= upper; i++) {
            if (n % i == 0) {
                chosen.push_back(i);
                helper(n / i, result, chosen, i);
                chosen.pop_back();
            }
        }
    }
};