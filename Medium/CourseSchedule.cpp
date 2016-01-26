class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0) return true;
        vector<vector<int>> graph(numCourses);
        for (auto p: prerequisites) {
            graph[p.second].push_back(p.first);
        }
        vector<bool> visited(numCourses, false);
        unordered_set<int> startNodes;
        for (int i = 0; i < numCourses; i++) startNodes.insert(i);
        while (!startNodes.empty()) {
            int node = *(startNodes.begin());
            if (dfsLoopDetection(graph, visited, node, startNodes)) return false;
        }
        return true;
    }
    
    bool dfsLoopDetection(const vector<vector<int>>& graph, vector<bool>& visited, int node, unordered_set<int>& startNodes) {
        visited[node] = true;
        for (int neighbor: graph[node]) {
            if (visited[neighbor]) return true;
            if (dfsLoopDetection(graph, visited, neighbor, startNodes)) return true;
        }
        visited[node] = false;
        startNodes.erase(node);
        return false;
    }
};