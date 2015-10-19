class Solution {
public:
    bool isStrobogrammatic(string num) {
        int start = 0, end = num.size() - 1;
        while (start <= end) {
            if (num[start] == '0' && num[end] == '0' ||
                num[start] == '1' && num[end] == '1' ||
                num[start] == '6' && num[end] == '9' ||
                num[start] == '9' && num[end] == '6' ||
                num[start] == '8' && num[end] == '8') {
                    start++;
                    end--;
            } else {
                return false;
            }
        }
        return true;
    }
};