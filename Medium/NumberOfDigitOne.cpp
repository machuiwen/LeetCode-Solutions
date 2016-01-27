class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        typedef long long int lli;
        lli count = 0;
        lli scale = 10;
        while (scale / 10 <= n) {
            int digit = (n % scale) / (scale / 10);
            lli begin = n / scale;
            lli rest = n % (scale / 10);
            count += begin * (scale / 10);
            if (digit == 1) {
                count += rest + 1;
            } else if (digit > 1) {
                count += scale / 10;
            }
            scale *= 10;
        }
        return count;
    }
};