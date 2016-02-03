class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> slidingWindow;
        for (int i = 0; i < nums.size(); i++) {
            if (slidingWindow.size() == k + 1) {
                slidingWindow.erase(nums[i - k - 1]);
            }
            if (slidingWindow.count(nums[i])) {
                return true;
            } else {
                slidingWindow.insert(nums[i]);
            }
        }
        return false;
    }
};