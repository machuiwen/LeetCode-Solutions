class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() < 4) return res;
        string chosen;
        helper(s, chosen, 1, res);
        return res;
    }
    
    void helper(string s, string& chosen, int n, vector<string>& res) {
        if (s.empty() || n > 4) return;
        if (n == 4) {
            if ((s[0] == '0' && s == "0") || (s[0] != '0' && s.size() <= 3 && stoi(s) <= 255)) {
                res.push_back(chosen + s);
            } else {
                return;
            }
        }
        int iMax = (s[0] == '0') ? 0 : min(2, int(s.size()) - 1);
        for (int i = 0; i <= iMax; i++) {
            string sub = s.substr(0, i + 1);
            if (stoi(sub) <= 255) {
                chosen += sub + '.';
                helper(s.substr(i + 1), chosen, n + 1, res);
                chosen.erase(chosen.end() - i - 2, chosen.end());
            }
        }
    }
};