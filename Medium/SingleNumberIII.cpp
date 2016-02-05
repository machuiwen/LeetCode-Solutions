class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x_xor_y = 0;
        for (int n: nums) {
            x_xor_y ^= n;
        }
        // find the last set bit - 
        // The last bit that x =/= y
        int mask = x_xor_y & ~(x_xor_y - 1);
        int x = 0;
        int y = 0;
        // x: XOR of a,a,b,b,x
        // y: XOR of c,c,y
        for (int n: nums) {
            if (n & mask) {
                x ^= n;
            } else {
                y ^= n;
            }
        }
        return vector<int> {x, y};
    }
};