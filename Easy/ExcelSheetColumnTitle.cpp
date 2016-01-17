class Solution {
public:
    string convertToTitle(int n) {
        string result = string();
        if (n == 1) return "A";
        while (n > 0) {
            n -= 1;
            result = (char)(n % 26 + 'A') + result;
            n /= 26;
        }
        return result;
    }
};