class Solution {
public:
    // The core issue of DP problem is to find the 'f(n) - f(n-1)' function
    // Besides keeping track of the largest product, we also need to
    // keep track of the smallest product. Why? The smallest product,
    // which is the largest in the negative sense could become the 
    // maximum when being multiplied by a negative number.
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int maxProdSub = nums[0];
        int maxCur = nums[0], minCur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int mx = maxCur, mn = minCur;
            maxCur = max(max(mx * nums[i], mn * nums[i]), nums[i]);
            minCur = min(min(mx * nums[i], mn * nums[i]), nums[i]);
            maxProdSub = max(maxProdSub, maxCur);
        }
        return maxProdSub;
    }
};