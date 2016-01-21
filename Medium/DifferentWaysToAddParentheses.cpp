class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int n = input.size();
        bool allDigits = true;
        for (int i = 0; i < n; i++) {
            if (!isdigit(input[i])) {
                vector<int> v1 = diffWaysToCompute(input.substr(0, i));
                vector<int> v2 = diffWaysToCompute(input.substr(i + 1));
                for (int j: v1) {
                    for (int k: v2) {
                        switch (input[i]) {
                            case '+':
                                res.push_back(j + k);
                                break;
                            case '-':
                                res.push_back(j - k);
                                break;
                            case '*':
                                res.push_back(j * k);
                                break;
                        }
                    }
                }
                allDigits = false;
            }
        }
        if (allDigits) return vector<int>(1, stoi(input));
        else return res;
    }
};