class Solution {
public:
    int myAtoi(string str) {
        // remove leading spaces
        int start = 0;
        while (start < str.size() && str[start] == ' ') start++;
        // find optional sign symbol
        int sign = 1;
        if (start == str.size()) return 0;
        else if (str[start] == '+') {
            start++;
        } else if (str[start] == '-') {
            start++;
            sign = -1;
        }
        // get result
        int result = 0;
        for (int i = start; i < str.length() && isdigit(str[i]); i++) {
            // handling overflow
            if (result > 214748364 || (result == 214748364 && str[i] >= '8')) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + int(str[i] - '0');
        }
        return sign * result;
    }
};