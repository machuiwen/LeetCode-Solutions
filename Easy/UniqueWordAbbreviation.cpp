class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string word: dictionary) {
            if (words.find(word) == words.end()) {
                myMap[abbrFromWord(word)]++;
            }
            words.insert(word);
        }
    }

    bool isUnique(string word) {
        string abbr = abbrFromWord(word);
        if (words.find(word) == words.end()) {
            return myMap.find(abbr) == myMap.end();
        } else {
            return myMap.find(abbr) == myMap.end() ||
                   myMap[abbr] == 1;
        }
    }
    
private:
    unordered_map<string, int> myMap;
    unordered_set<string> words;
    
    string abbrFromWord(string word) {
        if (word.size() <= 2) return word;
        return string() + word.front() + to_string(word.size() - 2) + word.back();
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");