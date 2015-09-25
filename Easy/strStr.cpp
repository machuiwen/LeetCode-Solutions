class Solution {
public:
    int strStr(string haystack, string needle) {
        // if the needle is empty string, always return 0
        if (needle.length() == 0) return 0;
        // if the haystack is shorter than the needle, must return -1
        if (haystack.length() < needle.length()) return -1;
        
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            int j;
            for (j = 0; j < needle.length(); j++) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == needle.length()) return i;
        }
        return -1;
    }
};