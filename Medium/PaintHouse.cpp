class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        vector<int> curMinCost = costs[0];
        for (int i = 1; i < costs.size(); i++) {
            vector<int> tempMinCost(3, 0);
            tempMinCost[0] = costs[i][0] + min(curMinCost[1], curMinCost[2]);
            tempMinCost[1] = costs[i][1] + min(curMinCost[0], curMinCost[2]);
            tempMinCost[2] = costs[i][2] + min(curMinCost[0], curMinCost[1]);
            curMinCost = tempMinCost;
        }
        return min(min(curMinCost[0], curMinCost[1]), curMinCost[2]);
    }
};