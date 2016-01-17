class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int step = numRows + (numRows - 2);
        string result;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.size(); j += step) {
                result += s[j];
                if (i != 0 && i != numRows - 1 && (j + step - 2 * i) < s.size()) {
                    result += s[j + step - 2 * i];
                }
            }
        }
        return result;
    }
};