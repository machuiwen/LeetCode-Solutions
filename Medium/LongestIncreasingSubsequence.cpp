class Solution {
public:
    // O(n logn) solution
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int n = nums.size();
        vector<int> IS(n);
        int len = 0;
        IS[len++] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > IS[len - 1]) {
                IS[len++] = nums[i];
            } else {
                int position = binarySearchFindReplacePosition(IS, nums[i], 0, len - 1);
                IS[position] = nums[i];
            }
        }
        return len;
    }

    int binarySearchFindReplacePosition(vector<int>& nums, int target, int start, int end) {
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};