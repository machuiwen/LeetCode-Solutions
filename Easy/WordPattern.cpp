class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream s; // convert from str to words
        s << str;
        unordered_map<char, string> mapping;
        unordered_set<string> existingWords;
        string word;
        for (int i = 0; i < pattern.size(); i++) {
            // read word
            if (!(s >> word)) return false;
            if (mapping.find(pattern[i]) == mapping.end()) {
                if (existingWords.count(word)) return false;
                mapping[pattern[i]] = word;
                existingWords.insert(word);
            } else if (mapping[pattern[i]] != word) {
                return false;
            }
        }
        if (s >> word) return false;
        else return true;
    }
};