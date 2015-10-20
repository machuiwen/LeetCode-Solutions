class Solution {
public:
    // O(n^2) time, O(1) space
    string longestPalindrome(string s) {
        int substrStart = 0, substrEnd = -1;
        for (float i = 0; i < s.size(); i += 0.5) {
            int start = int(i);
            int end = int(i + 0.5);
            while (start >= 0 && end < s.size() && s[start] == s[end]) {
                start--;
                end++;
            }
            start++; end--;
            if (end - start > substrEnd - substrStart) {
                substrStart = start;
                substrEnd = end;
            }
        }
        return s.substr(substrStart, substrEnd - substrStart + 1);
    }
};