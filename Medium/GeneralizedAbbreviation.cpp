class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res(1 << word.size());
        for(int i = 0; i < word.size(); i++){
            for(int j = 0; j < res.size(); j++){
                if(j & (1 << i)) res[j].push_back(word[i]);
                else{  // plus one
                    int k = res[j].size()-1, carry=1;
                    while (k >= 0 && isdigit(res[j][k]) && carry == 1){
                        int cur = (res[j][k] - '0') + carry;
                        res[j][k--] = cur % 10 + '0';
                        carry = cur / 10;
                    }
                    if (carry == 1) res[j].insert(res[j].begin() + k + 1, '1');
                }
            }
        }
        return res;
    }
};