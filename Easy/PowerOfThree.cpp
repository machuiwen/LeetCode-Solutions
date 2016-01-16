class Solution {
public:
    bool isPowerOfThree(int n) {
        double log3n = log10(n) / log10(3);
        return log3n - int(log3n) == 0;
    }
};