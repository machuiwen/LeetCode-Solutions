class Solution {
public:
	// Trick: missing number is the overall sum - 
	// the sum of the elements in the array
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) return 0;
        int sum = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            sum += nums[i];
        }
        return (size + 1) * size / 2 - sum;
    }
};