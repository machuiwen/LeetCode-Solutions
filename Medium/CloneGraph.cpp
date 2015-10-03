/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    // Note: DFS or BFS
    // c++ containers should pass by reference !!
    // -------- This is the DFS solution ----------
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
        return DFS(node, nodeMap);
    }
    
    UndirectedGraphNode* DFS(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& nodeMap) {
        if (nodeMap.find(node) != nodeMap.end()) return nodeMap.find(node)->second;
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        nodeMap.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(node, newNode));
        for (int i = 0; i < node->neighbors.size(); i++) {
            newNode->neighbors.push_back(DFS(node->neighbors[i], nodeMap));
        }
        return newNode;
    }
};


// Solution 2
class Solution {
public:
    // -------- This is the BFS solution ----------
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
        queue<UndirectedGraphNode*> BFSQueue;
        BFSQueue.push(node);
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        nodeMap.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(node, newNode));
        while (!BFSQueue.empty()) {
            UndirectedGraphNode* cur = BFSQueue.front();
            BFSQueue.pop();
            for (int i = 0; i < cur->neighbors.size(); i++) {
                auto it = nodeMap.find(cur->neighbors[i]);
                if (it == nodeMap.end()) {
                    UndirectedGraphNode* n = new UndirectedGraphNode(cur->neighbors[i]->label);
                    nodeMap.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(cur->neighbors[i], n));
                    nodeMap.find(cur)->second->neighbors.push_back(n);
                    BFSQueue.push(cur->neighbors[i]);
                } else {
                    nodeMap.find(cur)->second->neighbors.push_back(it->second);
                }
            }
        }
        return newNode;
    }
};