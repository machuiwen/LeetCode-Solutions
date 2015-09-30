class Solution {
public:
    // See LeetCode book pg19 for explanation
    int lengthOfLongestSubstring(string s) {
        vector<bool> exist(256, false);
        int i = 0;
        int maxLen = 0;
        for (int j = 0; j < s.size(); j++) {
            while (exist[s[j]]) {
                exist[s[i]] = false;
                i++;
            }
            exist[s[j]] = true;
            maxLen = max(j - i + 1, maxLen);
        }
        return maxLen;
    }
};