class Solution {
public:
    // General idea: first reverse every character in the string
    // then reverse every word.
    void reverseWords(string &s) {
        if (s.empty()) return;
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        reverse(s, start, s.size() - 1);
    }
    
    void reverse(string &s, int start, int end) {
        while (start < end) {
            char c = s[start];
            s[start] = s[end];
            s[end] = c;
            start++;
            end--;
        }
    }
};