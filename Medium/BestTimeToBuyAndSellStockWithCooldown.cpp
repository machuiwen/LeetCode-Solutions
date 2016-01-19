class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 3 status
        // hold: during this round I keep my existing stock, or buy in
        // not hold: during this round I don't have anystock, and I am not selling
        // cooldown: during this round I am selling all my stock
        int hold = INT_MIN;
        int notHold = 0;
        int cooldown = INT_MIN;
        // DP
        for (int p: prices) {
            int hold_ = max(hold, notHold - p);
            int notHold_ = max(notHold, cooldown);
            int cooldown_ = hold + p;
            hold = hold_;
            notHold = notHold_;
            cooldown = cooldown_;
        }
        return max(notHold, cooldown);
    }
};