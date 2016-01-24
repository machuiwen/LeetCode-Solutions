class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> m;
        for (char c: s) {
            m[c]++;
        }
        int countOfOdd = 0;
        string sNew;
        char middle = -1;
        for (auto p: m) {
            sNew += string(p.second / 2, p.first);
            if (p.second % 2) {
                countOfOdd++;
                middle = p.first;
            }
        }
        if (countOfOdd > 1) return vector<string>();
        sort(sNew.begin(), sNew.end());
        vector<string> res;
        do {
            res.push_back(sNew);
        } while (next_permutation(sNew.begin(), sNew.end()));
        for (int i = 0; i < res.size(); i++) {
            string r = reverse(res[i]);
            if (middle != -1) res[i] += middle;
            res[i] += r;
        }
        return res;
    }
    
    string reverse(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
            i++;
            j--;
        }
        return s;
    }
};