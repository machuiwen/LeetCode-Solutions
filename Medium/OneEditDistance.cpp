class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() > t.size()) return isOneEditDistance(t, s);
        // size(s) < size(t)
        if (t.size() - s.size() > 1) return false;
        // size(t) - size(s) <= 1
        if (s.size() == t.size()) {
            int diff = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != t[i]) diff++;
                if (diff == 2) return false;
            }
            return diff == 1;
        } else {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != t[i]) {
                    return s.substr(i) == t.substr(i + 1);
                }
            }
            return true;
        }
    }
};