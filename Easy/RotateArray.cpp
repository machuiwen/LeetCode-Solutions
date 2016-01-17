class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        nums.insert(nums.begin(), nums.end() - k, nums.end());
        nums.erase(nums.end() - k, nums.end());
    }
};