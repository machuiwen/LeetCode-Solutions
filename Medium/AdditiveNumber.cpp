class Solution {
public:
    typedef long long int lli;
    bool isAdditiveNumber(string num) {
        int n = num.size();
        if (n < 3) return false;
        int iMax = (num[0] == '0') ? 0 : ((n - 1) / 2 - 1);
        int jMax = n - (n + 2) / 3 - 1;
        // num[0:i] number 1
        // num[i+1:j] number 2
        for (int i = 0; i <= iMax; i++) {
            // have to use String-To-Long-Long stoll
            lli n1 = stoll(num.substr(0, i + 1));
            int jMaxNew = (num[i + 1] == '0') ? (i + 1) : jMax;
            for (int j = i + 1; j <= jMaxNew; j++) {
                lli n2 = stoll(num.substr(i + 1, j - i));
                if (check(num.substr(j + 1), n1, n2)) return true;
            }
        }
        return false;
    }
    
    bool check(string num, lli n1, lli n2) {
        lli n3 = n1 + n2;
        string s = to_string(n3);
        int lenS = s.size(), lenN = num.size();
        if (lenN < lenS) {
            return false;
        } else if (lenN == lenS) {
            return num == s;
        } else {
            return check(num.substr(lenS), n2, n3);
        }
    }
};