class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int cur = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] != val) {
                nums[cur] = nums[i];
                cur++;
            }
        }
        return cur;
    }
};