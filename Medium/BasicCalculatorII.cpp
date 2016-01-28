class Solution {
public:
    // stack solution
    int calculate(string s) {
        stack<int> myStack;
        int len = s.size();
        int temp = 0;
        char sign = '+';
        for (int i = 0; i < len; i++) {
            if (isdigit(s[i])) {
                temp = temp * 10 + s[i] - '0';
            } 
            if (!isdigit(s[i]) && !isspace(s[i]) || i == len - 1) {
                if (sign == '+') {
                    myStack.push(temp);
                } else if (sign == '-') {
                    myStack.push(-temp);
                } else if (sign == '*') {
                    int newElement = myStack.top() * temp;
                    myStack.pop();
                    myStack.push(newElement);
                } else { // divide
                    int newElement = myStack.top() / temp;
                    myStack.pop();
                    myStack.push(newElement);
                }
                temp = 0;
                sign = s[i];
            }
        }
        int res = 0;
        while (!myStack.empty()) {
            res += myStack.top();
            myStack.pop();
        }
        return res;
    }
};