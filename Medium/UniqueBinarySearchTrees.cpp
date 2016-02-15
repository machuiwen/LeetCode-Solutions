class Solution {
public:
    int numTrees(int n) {
        vector<int> numTrees(n + 1, 0);
        numTrees[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                numTrees[i] += numTrees[j] * numTrees[i - 1 - j];
            }
        }
        return numTrees[n];
    }
};