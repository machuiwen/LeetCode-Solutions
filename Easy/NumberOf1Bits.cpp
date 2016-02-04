class Solution {
public:
    // Brian Kernighan’s Algorithm
    // http://www.geeksforgeeks.org/count-set-bits-in-an-integer/
    int hammingWeight(uint32_t n) {
        int count  = 0;
        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};