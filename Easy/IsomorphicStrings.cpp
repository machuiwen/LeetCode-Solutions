class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        else if (s.size() == 0) return true;
        unordered_map<char, char> m;
        unordered_set<char> destSet;
        for (int i = 0; i < s.size(); i++) {
            if (m.count(s[i])) {
                if (m[s[i]] != t[i]) return false;
            } else {
                if (destSet.count(t[i])) return false;
                m[s[i]] = t[i];
                destSet.insert(t[i]);
            }
        }
        return true;
    }
};