class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        unordered_set<string> once;
        unordered_set<string> repeated;
        for (int i = 0; i <= len - 10; i++) {
            string sub = s.substr(i, 10);
            if (once.find(sub) != once.end() && repeated.find(sub) == repeated.end()) {
                repeated.insert(sub);
            } else {
                once.insert(sub);
            }
        }
        vector<string> res;
        res.insert(res.end(), repeated.begin(), repeated.end());
        return res;
    }
};