class Solution {
public:
    // O(n) complexity.
    // Core idea: for the same cumulative sum value, we
    // only keep it's first appearance, so at last the
    // subarray is guaranteed to be the longest.
    // Also, note the brilliant idea of using the sum value
    // as the key of the map.
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> cumSum;
        int sum = 0;
        int maxLen = 0;
        cumSum[sum] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (cumSum.find(sum) == cumSum.end()) {
                cumSum[sum] = i;
            }
            if (cumSum.find(sum - k) != cumSum.end()) {
                maxLen = max(maxLen, i - cumSum[sum - k]);
            }
        }
        return maxLen;
    }
};