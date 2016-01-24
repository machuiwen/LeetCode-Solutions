class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if (s.empty()) return result;
        vector<string> chosen;
        helper(s, chosen, result);
        return result;
    }
    
    void helper(string s, vector<string>& chosen, vector<vector<string>>& result) {
        if (isPalindrome(s)) {
            chosen.push_back(s);
            result.push_back(chosen);
            chosen.pop_back();
        }
        for (int i = 1; i <= s.size() - 1; i++) {
            string temp = s.substr(0, i);
            if (isPalindrome(temp)) {
                chosen.push_back(temp);
                helper(s.substr(i), chosen, result);
                chosen.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
    }
};