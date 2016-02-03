class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0 || strs[0].size() == 0) return string();
        for (int id = 0; id < strs[0].size(); id++) {
            for (int i = 0; i < n; i++) {
                if (strs[i].size() <= id || strs[i][id] != strs[0][id]) {
                    return strs[0].substr(0, id);
                }
            }
        }
        return strs[0];
    }
};