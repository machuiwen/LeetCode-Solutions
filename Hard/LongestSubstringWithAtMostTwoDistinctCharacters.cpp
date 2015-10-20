class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i = 0, j = -1, maxLen = 0;
        for (int k = 1; k < s.size(); k++) {
            if (s[k] == s[k - 1]) continue;
            if (j >= 0 && s[j] != s[k]) {
                maxLen = max(k - i, maxLen);
                i = j + 1;
            }
            j = k - 1;
        }
        return max(int(s.size() - i), maxLen);
    }
};