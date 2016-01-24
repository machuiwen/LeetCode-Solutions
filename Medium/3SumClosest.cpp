class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int p = i + 1;
            int q = nums.size() - 1;
            while (p < q) {
                int s = nums[i] + nums[p] + nums[q];
                if (abs(s - target) < abs(closestSum - target)) {
                    closestSum = s;
                }
                if (s > target) {
                    q--;
                } else if (s < target) {
                    p++;
                } else {
                    return target;
                }
            }
        }
        return closestSum;
    }
};