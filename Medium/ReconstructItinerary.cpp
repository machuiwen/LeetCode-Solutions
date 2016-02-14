class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        if (tickets.empty()) return res;
        unordered_map<string, multiset<string>> graph;
        for (auto p: tickets) {
            graph[p.first].insert(p.second);
        }
        dfs(graph, res, "JFK");
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool dfs(unordered_map<string, multiset<string>>& graph, vector<string>& res, string current) {
        while (!graph[current].empty()) {
            string des = *graph[current].begin();
            graph[current].erase(graph[current].begin());
            dfs(graph, res, des);
        }
        res.push_back(current);
    }
};