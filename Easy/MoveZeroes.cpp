class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // find the first zero
        int zeroIndex = 0;
        while (zeroIndex < nums.size()) {
            if (nums[zeroIndex] == 0) break;
            zeroIndex++;
        }
        if (zeroIndex == nums.size()) return;
        // move elements
        int cur = zeroIndex + 1;
        while (cur < nums.size()) {
            // how many elements we move, the zeroIndex will
            // shift how many steps
            while (nums[cur] != 0 && cur < nums.size()) {
                nums[zeroIndex] = nums[cur];
                nums[cur] = 0;
                zeroIndex++;
                cur++;
            }
            cur++;
        }
    }
};