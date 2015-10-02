class Solution {
public:
	// O(n) time, O(1) space
    int climbStairs(int n) {
        int n1 = 1, n2 = 1;
        for (int i = 2; i <= n; i++) {
            int temp = n2;
            n2 = n1;
            n1 = n1 + temp;
        }
        return n1;
    }
};