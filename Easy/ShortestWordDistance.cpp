class Solution {
public:
    // The shortest word distance must be between two consecutive word1, word2
    // I.e., no word1 and word2 is between this range
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int id1 = -1, id2 = -1;
        int minDist = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                id1 = i;
                if (id2 != -1) {
                    minDist = min(minDist, id1 - id2);
                }
            } else if (words[i] == word2) {
                id2 = i;
                if (id1 != -1) {
                    minDist = min(minDist, id2 - id1);
                }
            }
        }
        return minDist;
    }
};