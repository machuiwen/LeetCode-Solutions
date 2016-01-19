// Game of life, the most naive solution.
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        int m = board.size(), n = board[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                for (int x = max(0, i - 1); x <= min(m - 1, i + 1); x++) {
                    for (int y = max(0, j - 1); y <= min(n - 1, j + 1); y++) {
                        if (x == i && y == j) continue;
                        count += board[x][y];
                    }
                }
                if (board[i][j] && count >= 2 && count <= 3) {
                    res[i][j] = 1;
                } else if (board[i][j] == 0 && count == 3) {
                    res[i][j] = 1;
                } else {
                    res[i][j] = 0;
                }
            }
        }
        board = res;
    }
};

// In-place solution
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        if (n < 0) return;
        int m = board[0].size();
        if (m < 0) return;
        /*
        11:1->1
        18:1->0
        81:0->1
        88:0->0
        */
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                int iu = max(0, i - 1), iv = min(i + 1, n - 1);
                int ju = max(0, j - 1), jv = min(j + 1, m - 1);
                int c = 0 - board[i][j];
                for (int a = iu; a <= iv; ++a)
                    for (int b = ju; b <= jv; ++b){
                        int t = board[a][b];
                        if (t == 1 || t == 18 || t == 11) 
                            ++c;
                    }
                if (board[i][j] == 0){
                    board[i][j] = (c == 3) ? 81 : 88;
                } else {
                    board[i][j] = (c == 2 || c == 3) ? 11 : 18;
                }
            }
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
               board[i][j] = (board[i][j] % 10 == 8) ? 0 : 1;
            }
        }
    }
};