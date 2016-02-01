class Solution {
public:
    int calculate(string s) {
        stack<int> myStack;
        int len = s.size(), res = 0, sign = 1;
        for (int i = 0; i < len; i++) {
            if (isdigit(s[i])) {
                int num = 0;
                while (isdigit(s[i]) && i < len) {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                res += num * sign;
                i--;
            } else if (s[i] == '+') {
                sign = 1;
            } else if (s[i] == '-') {
                sign = -1;
            } else if (s[i] == '(') {
                myStack.push(res);
                myStack.push(sign);
                res = 0;
                sign = 1;
            } else if (s[i] == ')') {
                res = res * myStack.top();
                myStack.pop();
                res += myStack.top();
                myStack.pop();
            }
        }
        return res;
    }
};