class Solution {
public:
    // Algorithm: http://blog.xiaohuahua.org/2015/01/22/lintcode-single-number-iii/
    vector<int> singleNumber(vector<int>& nums) {
        int x_xor_y = 0;
        for (int i = 0; i < nums.size(); i++) {
            x_xor_y ^= nums[i];
        }
        // find the last bit
        int mask = x_xor_y & ~(x_xor_y - 1);
        int x = 0;
        int y = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & mask) {
                x ^= nums[i];
            } else {
                y ^= nums[i];
            }
        }
        return vector<int> {x, y};
    }
};