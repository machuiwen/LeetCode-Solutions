class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string> myStack;
        int start = 0;
        int len = preorder.size();
        for (int i = 0; i < len; i++) {
            if ((preorder[i + 1] == ',' && i < len - 1) || i == len - 1) {
                string val = preorder.substr(start, i - start + 1);
                start = i + 2;
                if (val == "#") {
                    while (myStack.size() > 1 && myStack.top() == "#") {
                        myStack.pop();
                        if (myStack.top() == "#") return false;
                        myStack.pop();
                    }
                }
                myStack.push(val);
            }
        }
        return myStack.size() == 1 && myStack.top() == "#";
    }
};