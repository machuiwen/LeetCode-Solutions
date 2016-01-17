class Solution {
public:
    string getHint(string secret, string guess) {
        int numBulls = 0;
        unordered_map<char, int> freqCountS;
        unordered_map<char, int> freqCountG;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) numBulls += 1;
            else {
                freqCountS[secret[i]] += 1;
                freqCountG[guess[i]] += 1;
            }
        }
        int numCows = 0;
        for (auto p: freqCountG) {
            if (freqCountS.find(p.first) != freqCountS.end()) {
                numCows += min(p.second, freqCountS[p.first]);
            }
        }
        return to_string(numBulls) + "A" + to_string(numCows) + "B";
    }
};