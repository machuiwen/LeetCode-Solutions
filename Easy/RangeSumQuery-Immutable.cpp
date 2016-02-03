class NumArray {
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        cumSum = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cumSum[i + 1] = cumSum[i] + nums[i];
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