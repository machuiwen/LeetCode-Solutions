class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;
        vector<int> res;
        while (start < end) {
            int sum = numbers[start] + numbers[end];
            if (sum == target) {
                res.push_back(start + 1);
                res.push_back(end + 1);
                return res;
            } else if (sum > target) {
                end--;
            } else {
                start++;
            }
        }
        return res;
    }
};