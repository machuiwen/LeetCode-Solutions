class Solution {
public:
    // Notice: the fence is not a loop. Just consider a line.
    // W(n) = Diff(n) + Same(n) - depends on the relationship of n-1 and n
    // Diff(n) = (k-1) * W(n - 1)
    // Same(n) = Diff(n - 1)
    // This solution cost O(1) space and O(n) time.
    int numWays(int n, int k) {
        if (n == 0) return 0;
        else if (k == 0) return 0;
        else if (n == 1) return k;
        // for n = 1
        int diff = k;
        int same = 0;
        for (int i = 2; i <= n; i++) {
            int diffTemp = (k - 1) * (diff + same);
            same = diff;
            diff = diffTemp;
        }
        return same + diff;
    }
};