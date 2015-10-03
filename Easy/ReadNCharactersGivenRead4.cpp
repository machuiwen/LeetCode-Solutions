// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        for (int i = 0; i < n / 4; i++) {
            int c = read4(buf);
            buf += 4;
            if (c != 4) return i * 4 + c;
        }
        if (n % 4 == 0) return n;
        else {
            int c = read4(buf);
            if (c <= n % 4) return n - (n % 4) + c;
            else {
                for (int i = n % 4; i < c; i++) {
                    *(buf + i) = '\0';
                }
                return n;
            }
        }
    }
};