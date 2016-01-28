class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cand(256, 0);
        vector<bool> visited(256, false);
        for (char c: s) {
            cand[c]++;
        }
        string res = "0";
        for (char c: s) {
            cand[c]--;
            if (visited[c]) continue;
            while (c < res.back() && cand[res.back()]) {
                visited[res.back()] = false;
                res.pop_back();
            }
            res += c;
            visited[c] = true;
        }
        return res.substr(1);
    }
};