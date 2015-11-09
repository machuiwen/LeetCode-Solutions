class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), std::greater<int>());
        int hIndex = 0;
        for (int i = 0; i < citations.size() && citations[i] >= i + 1; i++) {
            hIndex = i + 1;
        }
        return hIndex;
    }
};