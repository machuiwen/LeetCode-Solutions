class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n, true);
    }
    
    vector<string> helper(int n, bool outer) {
        // base case
        if (n == 0) {
            return vector<string>(1, "");
        } else if (n == 1) {
            return {"0", "1", "8"};
        }
        // recursion
        vector<string> v = helper(n - 2, false);
        vector<string> res;
        for (string s: v) {
            res.push_back("1" + s + "1");
            res.push_back("6" + s + "9");
            res.push_back("8" + s + "8");
            res.push_back("9" + s + "6");
            if (!outer) {
                res.push_back("0" + s + "0");
            }
        }
        return res;
    }
};