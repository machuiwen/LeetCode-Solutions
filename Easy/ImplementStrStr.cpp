class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.size(), l2 = needle.size();
        // if the needle is empty string, always return 0
        if (l2 == 0) return 0;
        // if the haystack is shorter than the needle, must return -1
        if (l1 < l2) return -1;
        
        for (int i = 0; i <= l1 - l2; i++) {
            int j;
            for (j = 0; j < l2; j++) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == l2) return i;
        }
        return -1;
    }
};