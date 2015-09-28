class Solution {
public:
    // Could you implement it without using extra memory?
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0, threes = -1;
        for (int i = 0; i < nums.size(); i++) {
            int newOnes = (threes & nums[i]) | (ones & ~nums[i]);
            int newTwos = (ones & nums[i]) | (twos & ~nums[i]);
            int newThrees = (twos & nums[i]) | (threes & ~nums[i]);
            ones = newOnes;
            twos = newTwos;
            threes = newThrees;
        }
        return ones;
    }
};

// Here is the leetcode solution, which is harder to understand
int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0, threes = 0;
    for (int i = 0; i < n; i++) {
        twos |= ones & nums[i];
        ones ^= nums[i];
        threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }
    return ones;
}