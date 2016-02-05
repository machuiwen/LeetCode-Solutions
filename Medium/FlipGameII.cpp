class Solution {
public:
    bool canWin(string s) {
        return canWinHelper(s);
    }
    
    bool canWinHelper(string& s) {
        for (int i = 0; i < int(s.size()) - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = '-';
                s[i + 1] = '-';
                if (!canWin(s)) return true;
                s[i] = '+';
                s[i + 1] = '+';
            }
        }
        return false;
    }
};