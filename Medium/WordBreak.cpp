class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> canBreak(n, false);
        for (int i = 0; i < n; i++) {
            if (wordDict.count(s.substr(0, i + 1))) {
                canBreak[i] = true;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (canBreak[j] && wordDict.count(s.substr(j + 1, i - j))) {
                    canBreak[i] = true;
                }
            }
        }
        return canBreak[n - 1];
    }
};