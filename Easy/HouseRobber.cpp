class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n1 = 0, n2 = nums[0], len = nums.size();
        for (int i = 1; i < len; i++) {
            int temp = n1;
            n1 = n2;
            n2 = max(nums[i] + temp, n1);
        }
        return n2;
    }
};