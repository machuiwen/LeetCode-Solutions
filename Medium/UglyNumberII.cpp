// My 92 ms approach
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        vector<long int> cur(1, 1);
        while (cur.size() < n) {
            int n1 = uglyMultiplyBy(2, cur);
            int n2 = uglyMultiplyBy(3, cur);
            int n3 = uglyMultiplyBy(5, cur);
            cur.push_back(min(min(n1, n2), n3));
        }
        return cur[n - 1];
    }
    
    long int uglyMultiplyBy(int factor, const vector<long int>& v) {
        long int Max = v.back();
        int start = 0, end = v.size() - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (factor * v[mid] <= Max) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return v[start] * factor;
    }
};
