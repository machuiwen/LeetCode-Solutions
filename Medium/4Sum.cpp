class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int len = nums.size();
        for (int i = 0; i < len - 3; i++) {
            if (nums[i] * 4 > target) return res; // return immediately
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = len - 1; j > i + 2; j--) {
                if (nums[j] * 4 < target) break; // break immediately
                if (j < len - 1 && nums[j] == nums[j + 1]) continue;
                int p = i + 1;
                int q = j - 1;
                while (p < q) {
                    int sum = nums[i] + nums[j] + nums[p] + nums[q];
                    if (sum > target) {
                        q--;
                    } else if (sum < target) {
                        p++;
                    } else {
                        vector<int> temp = {nums[i], nums[p], nums[q], nums[j]};
                        res.push_back(temp);
                        do {
                            p++;
                        } while (nums[p] == nums[p - 1] && p < q);
                        do {
                            q--;
                        } while (nums[q] == nums[q + 1] && p < q);
                    }
                }
            }
        }
        return res;
    }
};