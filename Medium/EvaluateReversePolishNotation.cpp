class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0) return 0;
        int start; // to store the start index of the operand
        return evalRPNHelper(tokens, tokens.size() - 1, start);
    }
    int evalRPNHelper(vector<string>& tokens, int last, int& start) {
        string op = tokens[last];
        // base case
        if (op != "+" && op != "-" && op != "*" && op != "/") {
            // must be an operand
            start = last;
            return stoi(op); // stoi throws an exception on invalid input
                             // while atoi just return 0
        }
        // recursively compute the second operand, set start to the
        // start of op2
        int operand2 = evalRPNHelper(tokens, last - 1, start);
        // compute the first operand
        int operand1 = evalRPNHelper(tokens, start - 1, start);
        
        if (op == "+") {
            return operand1 + operand2;
        } else if (op == "-") {
            return operand1 - operand2;
        } else if (op == "*") {
            return operand1 * operand2;
        } else if (op == "/") {
            return operand1 / operand2;
        } else {
            throw -1;
        }
    }
};