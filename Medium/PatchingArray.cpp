class Solution {
public:

    // Let miss be the smallest sum in [1,n] that we might be missing. Meaning we already know we can build all sums in [1,miss). Then if we have a number num <= miss in the given array, we can add it to those smaller sums to build all sums in [1,miss+num). If we don't, then we must add such a number to the array, and it's best to add miss itself, to maximize the reach.
    int minPatches(vector<int>& nums, int n) {
        // have to use long here, because miss may overflow
        long int miss = 1, added = 0, i = 0;
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                i++;
            } else {
                miss *= 2;
                added++;
            }
        }
        return added;
    }
};