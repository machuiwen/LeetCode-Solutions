class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0 || rooms[0].size() == 0) return;
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j] == 0) {
                    bfs(rooms, i, j);
                }
            }
        }
    }
    
    void bfs(vector<vector<int>>& rooms, int i, int j) {
        queue<pair<int, int>> q;
        q.push(pair<int, int>(i, j));
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            int cost = rooms[r][c];
            if (r > 0 && rooms[r - 1][c] > cost + 1) {
                rooms[r - 1][c] = cost + 1;
                q.push(pair<int, int>(r - 1, c));
            }
            if (r < rooms.size() - 1 && rooms[r + 1][c] > cost + 1) {
                rooms[r + 1][c] = cost + 1;
                q.push(pair<int, int>(r + 1, c));
            }
            if (c > 0 && rooms[r][c - 1] > cost + 1) {
                rooms[r][c - 1] = cost + 1;
                q.push(pair<int, int>(r, c - 1));
            }
            if (c < rooms[0].size() - 1 && rooms[r][c + 1] > cost + 1) {
                rooms[r][c + 1] = cost + 1;
                q.push(pair<int, int>(r, c + 1));
            }
        }
    }
};