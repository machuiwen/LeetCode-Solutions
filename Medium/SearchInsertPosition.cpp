class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // The possible range is [0, nums.size()]
        int start = 0;
        int end = nums.size();
        // If we don't reach the target index, loop continues
        while (end > start) {
            int mid = (start + end) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                // the possible range becomes [mid + 1, end]
                start = mid + 1;
            } else {
                // the possible range becomes [start, mid]
                end = mid;
            }
        }
        // find it
        return start;
    }
};