class Solution {
public:
    // Two-pass solution. 
    void reverseWords(string &s) {
        // first pass, store words in a vector
        bool wordStart = false;
        vector<string> words;
        for (int i = 0; i < s.size(); i++) {
            if (!wordStart && s[i] != ' ') {
                wordStart = true;
                words.push_back(string(1, s[i]));
            } else if (wordStart && s[i] != ' ') {
                words[words.size() - 1] += s[i];
            } else {
                wordStart = false;
            }
        }
        // second pass, generate target string
        s = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            s += words[i];
            if (i != 0) {
                s += ' ';
            }
        }
    }
};

//----------------------------------------------------
class Solution {
public:
    // One-pass solution
    void reverseWords(string &s) {
        string result;
        int wordEnd = s.size();
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                wordEnd = i;
            } else if (i == 0 || s[i - 1] == ' ') {
                if (result.size() != 0) {
                    result += ' ';
                }
                result += s.substr(i, wordEnd - i);
            }
        }
        s = result;
    }
};