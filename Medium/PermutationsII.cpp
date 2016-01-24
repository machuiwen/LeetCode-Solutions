class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        vector<bool> used(nums.size(), false);
        vector<int> chosen;
        sort(nums.begin(), nums.end());
        helper(nums, 0, used, chosen, res);
        return res;
    }
    
    void helper(vector<int>& nums, int pos, vector<bool>& used, vector<int>& chosen, vector<vector<int>>& res) {
        if (pos == nums.size()) {
            res.push_back(chosen);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]) continue;
            used[i] = true;
            chosen.push_back(nums[i]);
            helper(nums, pos + 1, used, chosen, res);
            used[i] = false;
            chosen.pop_back();
        }
    }
};