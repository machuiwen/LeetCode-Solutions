class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        int curLower = lower;
        for (int i = 0; i < nums.size(); i++) {
            if (curLower <= nums[i] - 1) {
                result.push_back(rangeToStr(curLower, nums[i] - 1));
            }
            curLower = nums[i] + 1;
        }
        if (curLower <= upper) {
            result.push_back(rangeToStr(curLower, upper));
        }
        return result;
    }
    
    string rangeToStr(int lower, int upper) {
        if (upper == lower) return to_string(lower);
        else return to_string(lower) + "->" + to_string(upper);
    }
};