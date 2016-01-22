class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        // build adjacency list from edges
        vector<vector<int>> graph(n);
        for (auto e: edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }
        // set of unvisited nodes
        unordered_set<int> nodes;
        for (int i = 0; i < n; i++) nodes.insert(i);
        if (!dfs(graph, nodes, 0, -1)) return false; // loop detected
        else if (!nodes.empty()) return false; // multiple connected components
        return true;
    }

    bool dfs(const vector<vector<int>>& graph, unordered_set<int>& nodes, int node, int ancestor) {
        nodes.erase(node);
        for (int neighbor: graph[node]) {
            if (neighbor != ancestor) {
                if (nodes.find(neighbor) == nodes.end()) return false;
                if (!dfs(graph, nodes, neighbor, node)) return false;
            }
        }
        return true;
    }
    
};