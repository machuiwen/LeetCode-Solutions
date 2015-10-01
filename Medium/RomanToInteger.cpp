class Solution {
public:
    int romanToInt(string s) {
        // this solution is too slow
        unordered_map<char, int> code = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        return romanToIntHelper(s, code);
    }
    int romanToIntHelper(string s, unordered_map<char, int>& code) {
        if (s.size() == 0) return 0;
        else if (s.size() == 1) return code.find(s[0])->second;
        else {
            if (code.find(s[0])->second < code.find(s[1])->second) {
                return romanToIntHelper(s.substr(2), code) + code.find(s[1])->second - code.find(s[0])->second;
            } else {
                return romanToIntHelper(s.substr(1), code) + code.find(s[0])->second;
            }
        }
    }
};