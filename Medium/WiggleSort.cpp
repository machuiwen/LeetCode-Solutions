class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1) return;
        for (int i = 0; i < nums.size() - 1; i++) {
            if ((i % 2 == 0 && nums[i] > nums[i + 1]) || (i % 2 == 1 && nums[i] < nums[i + 1])) {
                    int temp = nums[i];
                    nums[i] = nums[i + 1];
                    nums[i + 1] = temp;
            }
        }
    }
};