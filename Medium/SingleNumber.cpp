class Solution {
public:
	// Trick: x XOR x = 0
	//		  0 XOR x = x
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result = result ^ nums[i];
        }
        return result;
    }
};