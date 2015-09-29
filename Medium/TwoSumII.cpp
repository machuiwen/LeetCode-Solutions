class Solution {
public:
    // Strategy: two pointers. 
    vector<int> twoSum(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            if (nums[start] + nums[end] == target) {
                vector<int> result = {nums[start], nums[end]};
                return result;
            } else if (nums[start] + nums[end] > target) {
                end--;
            } else {
                start++;
            }
        }
        return vector<int>();
    }
};