class Solution {
public:
    // The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

    // The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

    // If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

    // If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
    
    // -------------MAIN CASES----------------------
    // 1. leading white spaces
    // 2. an optional '+' or '-'
    // 3. following digits bits as many as possible
    // 4. overflow, INT_MAX, INT_MIN
    // 5. if not a valid string, return 0
    
    int myAtoi(string str) {
        // remove leading spaces
        int start = 0, len = str.size();
        while (start < len && str[start] == ' ') start++;
        if (start == len) return 0;
        // find optional sign symbol
        int sign = 1;
        if (str[start] == '+') {
            start++;
        } else if (str[start] == '-') {
            start++;
            sign = -1;
        }
        // get result
        int result = 0;
        for (int i = start; i < len && isdigit(str[i]); i++) {
            // handling overflow
            if (result > 214748364 || (result == 214748364 && str[i] >= '8')) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + int(str[i] - '0');
        }
        return sign * result;
    }
};