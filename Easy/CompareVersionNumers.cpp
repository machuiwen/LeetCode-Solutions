class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1, s2;
        s1 << version1;
        s2 << version2;
        int v1, v2;
        char dot;
        while (true) {
            if (s1) s1 >> v1;
            else v1 = 0;
            if (s2) s2 >> v2;
            else v2 = 0;
            
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
            // only when both fail, return 0
            // when only one fail, use 0 to represent it
            else if (s1.fail() && s2.fail()) return 0;
            
            s1 >> dot;
            s2 >> dot;
        }
    }
};