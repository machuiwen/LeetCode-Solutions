class NumArray {
public:
    NumArray(vector<int> &nums) {
        cumSum = vector<int>(1, 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            cumSum.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return cumSum[j + 1] - cumSum[i];
    }
private:
    vector<int> cumSum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);