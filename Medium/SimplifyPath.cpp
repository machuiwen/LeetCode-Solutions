class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int start = 0;
        path += '/';
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (start < i) {
                    string cur = path.substr(start, i - start);
                    if (cur == "..") {
                        if (!s.empty()) s.pop();
                    } else if (cur != ".") {
                        s.push(cur);
                    }
                }
                start = i + 1;
            }
        }
        string res;
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
        return res.empty() ? "/" : res;
    }
};