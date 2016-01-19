class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            wordLocations[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        auto v1 = wordLocations[word1];
        auto v2 = wordLocations[word2];
        int minDist = INT_MAX;
        for (int n: v1) {
            int closest = binarySearch(v2, n);
            minDist = min(minDist, abs(n - closest));
        }
        return minDist;
    }
    
private:
    unordered_map<string, vector<int>> wordLocations;
    
    int binarySearch(const vector<int>& v, int target) {
        int start = 0;
        int end = v.size() - 1;
        while (start + 1 < end) { // more than 3 elements
            int mid = (start + end) / 2;
            if (target > v[mid]) {
                start = mid;
            } else if (target < v[mid]) {
                end = mid;
            }
            // target = v[mid] is impossible.
        }
        if (start == end) return v[start];
        else {
            // start + 1 = end
            if (abs(v[start] - target) <= abs(v[end] - target)) {
                return v[start];
            } else {
                return v[end];
            }
        }
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");