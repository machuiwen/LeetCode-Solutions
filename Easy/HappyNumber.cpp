class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> mySet;
        while (n != 1 && mySet.find(n) == mySet.end()) {
            mySet.insert(n);
            n = sumOfSquare(n);
        }
        return n == 1;
    }
    int sumOfSquare(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};