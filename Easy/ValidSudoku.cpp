class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        assert(board.size() == 9 && board[0].size() == 9);
        unordered_set<char> mySet;
        for (int i = 0; i < 9; i++) {
            mySet.clear();
            for (char& c: board[i]) {
                if (c >= '1' && c <= '9') {
                    if (mySet.count(c)) return false;
                    mySet.insert(c);
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            mySet.clear();
            for (int j = 0; j < 9; j++) {
                char c = board[j][i];
                if (c >= '1' && c <= '9') {
                    if (mySet.count(c)) return false;
                    mySet.insert(c);
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mySet.clear();
                for (int p = 0; p < 3; p++) {
                    for (int q = 0; q < 3; q++) {
                        char c = board[i * 3 + p][j * 3 + q];
                        if (c >= '1' && c <= '9') {
                            if (mySet.count(c)) return false;
                            mySet.insert(c);
                        }
                    }
                }
            }
        }
        return true;
    }
};