class Solution {
public:
    // Notice: here, compute the Int representation
    // of each word is high cost and repeatetive, so
    // we use a vector to store it.
    // Also mention static_cast<int>, is the C++
    // style type cast. From size_t to int.
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (n <= 2) return 0;
        int maxLen = 0;
        vector<int> wordsAsInt(n, 0);
        for (int i = 0; i < n; i++) {
            for (char c: words[i]) {
                wordsAsInt[i] |= 1 << (c - 'a');
            }
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!(wordsAsInt[i] & wordsAsInt[j])) {
                    maxLen = max(maxLen, static_cast<int>(words[i].size() * words[j].size()));
                }
            }
        }
        return maxLen;
    }
};