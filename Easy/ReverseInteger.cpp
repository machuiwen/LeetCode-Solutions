class Solution {
public:
    int reverse(int x) {
        // here we don't need to handle positive and negative x
        // because / and % are still applicable in this case
        int result = 0;
        while (x != 0) {
            if (abs(result) > 214748364) return 0; // handle overflow
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }
};