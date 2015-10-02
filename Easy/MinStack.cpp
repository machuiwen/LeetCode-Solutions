class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;
    
public:
    void push(int x) {
        mainStack.push(x);
        // if x == currentMin, also push x to minStack
        // because when popping, x == currentMin will be
        // popped
        if (minStack.empty() || minStack.top() >= x) {
            minStack.push(x);
        }
    }

    void pop() {
        int x = mainStack.top();
        mainStack.pop();
        if (x == minStack.top()) {
            minStack.pop();
        }
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};