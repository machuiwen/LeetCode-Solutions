class Solution {
public:
    // Dynamic programming
    // O(n) time, O(1) space
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int maxSub = nums[0];
        int curSub = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curSub = max(curSub + nums[i], nums[i]);
            maxSub = max(maxSub, curSub);
        }
        return maxSub;
    }
};