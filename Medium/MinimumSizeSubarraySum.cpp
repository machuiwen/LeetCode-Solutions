class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int p = 0, q = 0, sum = 0;
        int minLen = INT_MAX;
        while (q < n) {
            while (q < n && sum < s) {
                sum += nums[q++];
            }
            if (sum < s) break;
            while (sum >= s && p < q) {
                sum -= nums[p++];
            }
            minLen = min(minLen, q - p + 1);
        }
        if (minLen == INT_MAX) return 0;
        return minLen;
    }
};