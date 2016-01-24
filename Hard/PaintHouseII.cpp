class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        if (k == 0) return 0;
        vector<int> curCost = costs[0];
        for (int i = 1; i < costs.size(); i++) {
            int minColor, minCost = INT_MAX;
            for (int j = 0; j < k; j++) {
                if (curCost[j] < minCost) {
                    minCost = curCost[j];
                    minColor = j;
                }
            }
            int secondMinCost = INT_MAX;
            for (int j = 0; j < k; j++) {
                if (j == minColor) continue;
                secondMinCost = min(secondMinCost, curCost[j]);
                curCost[j] = minCost + costs[i][j];
            }
            curCost[minColor] = secondMinCost + costs[i][minColor];
        }
        return *min_element(curCost.begin(), curCost.end());
    }
};