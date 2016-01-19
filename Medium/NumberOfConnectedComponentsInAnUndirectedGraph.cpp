class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto edge: edges) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
        unordered_set<int> nodes;
        for (int i = 0; i < n; i++) nodes.insert(i);
        int cc = 0;
        while (!nodes.empty()) {
            int node = *(nodes.begin());
            dfs(graph, nodes, node);
            cc++;
        }
        return cc;
    }
    
private:
    void dfs(const vector<vector<int>>& graph, unordered_set<int>& nodes, int startNode) {
        nodes.erase(startNode);
        for (int neighbor: graph[startNode]) {
            if (nodes.find(neighbor) != nodes.end()) {
                dfs(graph, nodes, neighbor);
            }
        }
    }
    
};