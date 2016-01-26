class Solution {
public:
    // https://leetcode.com/discuss/71763/share-some-thoughts
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 0) return vector<int>();
        if (n == 1) return vector<int>(1, 0);
        
        vector<unordered_set<int>> graph(n);
        for (auto e: edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) leaves.push_back(i);
        }
        
        while (n > 2) {
            n -= leaves.size();
            vector<int> newLeaves;
            for (int i: leaves) {
                int j = *(graph[i].begin());
                graph[j].erase(i);
                if (graph[j].size() == 1) newLeaves.push_back(j);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};