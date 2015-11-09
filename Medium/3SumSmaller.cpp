class Solution {
public:
    // Time: O(n^2)
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        // i must be the middle element
        for (int i = 1; i < nums.size() - 1; i++) {
            int newTarget = target - nums[i];
            int l = 0, r = nums.size() - 1;
            while (l < i && r > i) {
                if (nums[l] + nums[r] >= newTarget) {
                    r--;
                } else {
                    // r - i is the number of combinations
                    // with the smallest element = nums[l]
                    count += r - i;
                    l++;
                }
            }
        }
        return count;
    }
};