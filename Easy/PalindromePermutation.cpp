class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> charCount;
        for (int i = 0; i < s.size(); i++) {
            if (charCount.find(s[i]) == charCount.end()) {
                charCount.insert(pair<char, int>(s[i], 1));
            } else {
                charCount[s[i]]++;
            }
        }
        int oddCount = 0;
        for (auto it = charCount.begin(); it != charCount.end(); it++) {
            if (it->second % 2 == 1) {
                if (++oddCount == 2) return false;
            }
        }
        return true;
    }
};