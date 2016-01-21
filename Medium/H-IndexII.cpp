class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        int n = citations.size();
        int start = 0, end = n - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            int diff = citations[mid] - (n - mid);
            if (diff >= 0) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        // start == end
        if (citations[start] >= n - start) {
            return n - start;
        } else { // must be all < 0
            return 0;
        }
    }
};