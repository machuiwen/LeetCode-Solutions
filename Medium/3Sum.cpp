class Solution {
public:
    // trick is to handle duplicates, without handling
    // this, will timeout
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int p = i + 1;
            int q = len - 1;
            while (p < q) {
                int sum = nums[i] + nums[p] + nums[q];
                if (sum > 0) {
                    q--;
                } else if (sum < 0) {
                    p++;
                } else {
                    vector<int> temp = {nums[i], nums[p], nums[q]};
                    res.push_back(temp);
                    do {
                        p++;
                    } while (nums[p] == nums[p - 1] && p < q);
                    do {
                        q--;
                    } while (nums[q + 1] == nums[q] && p < q);
                }
            }
        }
        return res;
    }
};