class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        // Here we use multiset, sort + duplicate
        unordered_map<string, multiset<string>> groupMap;
        for (string s: strings) {
            if (!s.empty()) {
                // convert s to a base string, consider overflow!
                string sBase = s;
                for (int i = 0; i < sBase.size(); i++) {
                    sBase[i] = (sBase[i] - s[0] + 26) % 26;
                }
                // insert to map. Notice that, we sBase is first
                // inserted, c++ will automatically create a default
                // value (i.e. an empty multiset) for us, so no need
                // to judge here.
                groupMap[sBase].insert(s);
            }
        }
        vector<vector<string>> result;
        for (auto p: groupMap) {
            vector<string> temp;
            for (string s: p.second) {
                temp.push_back(s);
            }
            result.push_back(temp);
        }
        return result;
    }
};