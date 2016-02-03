class Solution {
public:
    int lengthOfLastWord(string s) {
        int last = s.size() - 1;
        while (last >= 0 && s[last] == ' ') last--;
        int start = last;
        while (start >= 0 && s[start] != ' ') start--;
        return last - start;
    }
};