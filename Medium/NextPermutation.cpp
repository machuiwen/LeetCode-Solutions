class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (next_permutation(nums.begin(), nums.end())) return;
        sort(nums.begin(), nums.end());
    }
};

// Method 2
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int indexToBeChanged = nums.size() - 1;
        while (nums[indexToBeChanged] <= nums[indexToBeChanged - 1] && indexToBeChanged >= 1) {
            indexToBeChanged--;
        }
        if (indexToBeChanged != 0) {
            swap(nums, indexToBeChanged - 1, binarySearch(nums, indexToBeChanged, nums.size() - 1, nums[indexToBeChanged - 1]));
        }
        reverse(nums, indexToBeChanged, nums.size() - 1);
    }
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
    }
    int binarySearch(vector<int>& nums, int start, int end, int target) {
        if (start == end) return start;
        int mid = (start + 1 + end) / 2;
        if (nums[mid] > target) {
            return binarySearch(nums, mid, end, target);
        } else {
            return binarySearch(nums, start, mid - 1, target);
        }
    }
};