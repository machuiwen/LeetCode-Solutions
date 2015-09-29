class Solution {
public:
    // The input string does not contain leading or trailing spaces
    // and the words are always separated by a single space.
    void reverseWords(string &s) {
        reverse(s, 0, s.size() - 1);
        int wordStart = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i + 1] == ' ' || i == s.size() - 1) {
                reverseWords(s, wordStart, i);
                wordStart = i + 2;
            }
        }
    }

    void reverse(string &s, int start, int end) {
        while (end > start) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};