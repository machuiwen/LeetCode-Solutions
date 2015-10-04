class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int lastId = -1;
        int minDist = INT_MAX;
        int id1 = -1, id2 = -1;
        if (word1 == word2) {
            for (int i = 0; i < words.size(); i++) {
                if (words[i] == word1) {
                    if (lastId != -1) {
                        minDist = min(minDist, i - lastId);
                    }
                    lastId = i;
                }
            }
        } else {
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
        }
        return minDist;
    }
};