class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string chosen = "";
        if (n != 0)
            generateParenthesisHelper(result, chosen, n, 0, 0);
        return result;
    }
    // backtracking may need more parameters
    void generateParenthesisHelper(vector<string>& result, string& chosen, int n, int left, int right) {
        if (left == right && left == n) {
            result.push_back(chosen);
            return;
        }
        if (left < n) {
            chosen += '(';
            generateParenthesisHelper(result, chosen, n, left + 1, right);
            chosen.pop_back();
        }
        if (right < left) {
            chosen += ')';
            generateParenthesisHelper(result, chosen, n, left, right + 1);
            chosen.pop_back();
        }
    }
};