class Solution {
public:
    // Assumption: no duplicates
    // Notice that if we subdivide the array into two,
    // one will always be sorted, while the other contains
    // the minimum.
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        // if nums[start] < nums[end], we immediately know
        // that nums[start] is the minimal value
        while (start < end && nums[start] > nums[end]) {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return nums[start];
    }
};