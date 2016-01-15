class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result = vector<vector<int>> (A.size(), vector<int> (B[0].size(), 0));
        // convert A to hashmap
        vector<unordered_map<int, int>> AStar(A.size(), unordered_map<int, int>()); 
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                if (A[i][j] != 0) {
                    AStar[i].insert(pair<int, int>(j, A[i][j]));
                }
            }
        }
        // convert B to hashmap
        vector<unordered_map<int, int>> BStar(B[0].size(), unordered_map<int, int>());  
        for (int i = 0; i < B[0].size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (B[j][i] != 0) {
                    BStar[i].insert(pair<int, int>(j, B[j][i]));
                }
            }
        }
        // compute final result
        for (int i = 0; i < AStar.size(); i++) {
            for (int j = 0; j < BStar.size(); j++) {
                for (auto it: AStar[i]) {
                    if (BStar[j].find(it.first) != BStar[j].end()) {
                        result[i][j] += it.second * BStar[j][it.first];
                    }
                }
            }
        }
        return result;
    }
};