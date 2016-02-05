class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        if (days <= 1) return 0;
        int profit = 0;
        for (int i = 1; i < days; i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};