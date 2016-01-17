class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;
        int curMin = nums[0];
        int curMax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == curMax + 1) {
                curMax++;
            } else {
                result.push_back(rangeToString(curMin, curMax));
                curMin = nums[i];
                curMax = nums[i];
            }
        }
        result.push_back(rangeToString(curMin, curMax));
        return result;
    }
    
    string rangeToString(int min, int max) {
        if (min == max) return to_string(min);
        else return to_string(min) + "->" + to_string(max);
    }
};