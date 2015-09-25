class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                vector<int> result = {map.find(target - nums[i])->second + 1, i + 1};
                return result;
            }
            map.insert(pair<int, int>(nums[i], i));
        }
    }
};