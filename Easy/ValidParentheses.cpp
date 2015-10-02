class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) return true;
        if (s.size() % 2 != 0) return false;
        stack<char> myStack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                myStack.push(s[i]);
                continue;
            }
            if (myStack.empty()) return false;
            switch (s[i]) {
                case ')':
                    if (myStack.top() != '(') return false;
                    else myStack.pop();
                    break;
                case ']':
                    if (myStack.top() != '[') return false;
                    else myStack.pop();
                    break;
                case '}':
                    if (myStack.top() != '{') return false;
                    else myStack.pop();
                    break;
            }
        }
        // Only when the stack is empty, return true!
        if (myStack.empty()) return true;
        else return false;
    }
};